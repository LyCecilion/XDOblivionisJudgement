# AGENTS.md

本文件是给 AI 代码审查和自动修改工具看的仓库级指令。处理本仓库任务时，必须先读本文件，再读 `README.md` 和 `CONVENTIONS.md`。

## 仓库目标

XDOblivionisJudgement 是 XDOJ C/C++ 题解仓库。这里的代码不是通用工程库，而是面向 OJ 提交、复习和展示的题解集合。

AI 的任务不是把题解改成大型工程风格，而是在 OJ 场景下保持：

1. 正确可靠：隐藏测试、边界输入、输出格式和资源限制优先。
2. 简洁清晰：代码短、直接、能看出核心思路。
3. 风格统一：遵循 `CONVENTIONS.md`、`.clang-format`、`.clang-tidy`。
4. 改动克制：只改和当前题目/请求直接相关的内容。

## 必读文件

开始任何审查或修改前，按顺序读取：

1. `README.md`：了解项目结构、工具命令和默认评测行为。
2. `CONVENTIONS.md`：题解代码规范，以它作为代码审查标准。
3. 相关题目的 `problems/<id>/README.md`、`problem.toml`、`main.c` 或 `main.cpp`。
4. 相关样例：`problems/<id>/samples/*.in` 和 `*.out`。

如果题目目录里有 `NOTES.md`，也要读取；它可能包含题解思路或已知坑点。

## 审查优先级

做 code review 时，必须先列问题，再给总结。问题按严重程度排序：

1. 会导致 WA、RE、TLE、MLE、UB 或隐藏测试失败的问题。
2. 输入边界、数组越界、整数溢出、浮点误差、字符串容量、排序比较器不满足严格弱序。
3. 输出格式问题，包括多余空格、缺少换行、`endl`、全角/半角标点、大小写不一致。
4. 与 `CONVENTIONS.md` 不一致的风格问题。
5. 可读性和局部简化建议。

不要把纯风格问题包装成正确性问题。不能确定会失败时，明确说明这是风险而非已确认 bug。

## 修改边界

- 默认只修改当前请求涉及的题目、模板、工具或文档。
- 不要批量重写所有题解，除非用户明确要求。
- 不要改变题目目录名、源文件名和 `problem.toml` 的 `id` / `source`，除非用户明确要求。
- 不要手工编辑 README 的题目列表；需要更新时运行 `just sync-list`。
- 不要删除样例、备份目录或用户未说明要清理的文件。
- 遇到已有未提交改动时，默认认为是用户改动，不能回滚。
- 如果题面、样例和代码互相矛盾，先指出矛盾，再选择最能解释本地样例和 OJ 行为的最小修改。

## C/C++ 题解规则

所有题解必须遵循 `CONVENTIONS.md`。重点检查：

- 文件头注释格式。
- `int main(void)`。
- K&R 大括号风格，单行分支也加花括号。
- C++ 使用 `#include <bits/stdc++.h>` 和 `using namespace std;`，不要额外包含标准库头。
- C++ 普通标准库符号不额外写 `std::`。
- C++ 题解根据题目输入格式选择 I/O 家族。普通空白分隔输入可用 `cin` / `cout`；固定格式输入或极大输入量可用 `scanf` / `printf`。
- 一道题内原则上只使用一个 I/O 家族，不要混用 `cin` / `cout` 与 `scanf` / `printf`。
- 只有使用 `cin` / `cout` 时，才初始化：

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

- 如果 C++ 题解选择 `scanf` / `printf`，不要写上面两行。
- 换行使用 `'\n'`，不要使用 `endl`。
- 常量使用 `UPPER_SNAKE_CASE`。
- C++ 结构体和 C typedef 类型使用 `PascalCase`。
- 排序比较器必须表达严格弱序。
- C 字符串输入必须写宽度，写入必须受容量约束，避免 `strcpy`、`strcat`、`sprintf`。
- 输出字面量必须照抄题面，特别注意 ASCII / 全角标点。

## OJ 正确性检查清单

审查或修改题解时，逐项确认：

- 输入失败时是否安全退出。
- 题面最大范围下数组和容器容量是否足够。
- 下标是否存在 0/1 基混用风险。
- 累加、乘法、组合数、金额、距离是否可能超出 `int`。
- 字符串读取是否会截断、越界或残留换行。
- 浮点输出是否设置精度，比较是否使用误差。
- 排序并列规则是否完整。
- 输出是否有前导空格、额外提示、缺失换行或错误标点。
- 样例通过是否只能覆盖普通路径；如边界明显缺失，应手工补测。

## 工具命令

常用命令：

```sh
just fmt <ID>
just test <ID>
just check <ID>
just bench <ID>
just memcheck <ID>
```

最小验证：

- 文档修改：检查 Markdown 内容和链接，不需要跑题解测试。
- 单题代码修改：运行 `just fmt <ID>`、`just test <ID>`、`just check <ID>`。
- 涉及数组、字符串、递归或内存风险：追加 `just memcheck <ID>`。
- 涉及复杂度或大输入：追加 `just bench <ID>`。
- 修改模板、工具或全局配置：至少抽测 1 个 C 题和 1 个 C++ 题。

如果本地缺少命令或环境无法运行，要在最终回复里明确说明没有跑哪些验证以及原因。

## 题目元数据和比较模式

- `problem.toml` 是题目的权威元数据。
- `language`、`source`、`time_limit_ms`、`memory_limit_mb`、`compare` 都要尊重本题配置。
- 仓库默认比较模式可能变化，不能凭记忆假设。需要时读取 `oj.defaults.toml` 和当前题目的 `problem.toml`。
- 如果题目对行尾空格、CRLF 或逐字节输出敏感，优先使用 `compare = "exact"`。

## 新增题目

新增题目时使用工具，不要手工复制目录：

```sh
just add <ID>
just add-c <ID>
```

新增后补齐：

- `problem.toml` 的 `title`、`difficulty`、必要的资源限制。
- `README.md` 的题面、输入说明、输出说明、样例。
- `samples/*.in` / `samples/*.out`。
- `main.cpp` 或 `main.c`。
- 如需更新根 README 题目列表，运行 `just sync-list`。

## 最终回复要求

完成任务后，最终回复应简洁说明：

- 改了哪些文件。
- 修复或新增了什么规则/逻辑。
- 跑了哪些验证命令。
- 哪些验证没有跑以及原因。

如果是审查任务，回复必须先列 findings；没有发现问题时明确说没有发现阻塞问题，并说明仍有哪类测试风险。
