# 编码规范

本规范适用于 [XDOblivionisJudgement](https://github.com/LyCecilion/XDOblivionisJudgement) 仓库中所有 C/C++ 题解代码。

> **适用范围说明：** 本规范为 XDOJ 在线判题环境定制。我们尽量按照工程项目的代码风格要求完成题解，但考虑到 `#include <bits/stdc++.h>` 和 `using namespace std;` 是 OJ 刷题的常规做法，在这里对这两种做法特别予以保留。

本仓库题解的优先级是：

1. **正确可靠**：通过隐藏测试、处理边界输入、匹配输出格式和遵守资源限制，比写法花哨更重要。
2. **简洁清晰**：代码应该让人一眼看出数据范围、核心状态和排序/判断规则。
3. **规范统一**：新增题目和整理旧题时，以本规范、`.clang-format`、`.clang-tidy` 为准。
4. **OJ 务实**：允许为提交效率保留模板、全量标准库头和轻量宏，但不能牺牲安全边界。

## 当前代码中需要改进的问题

整理旧题或新增题解时，优先修正以下问题：

- `main()`、`int main(void)` 混用 → 统一写 `int main(void)`
- 部分文件缺少文件头注释，或 `C++ Version` / `C++ version` 大小写不一致 → 统一按本规范模板
- 部分代码未按 K&R 风格格式化，函数和控制流左大括号另起一行 → 运行 `just fmt` 后提交
- 单行 `if` / `for` 省略花括号，例如 `if (!getline(...)) return 0;` → 一律补上花括号
- 已经 `using namespace std;` 后仍大量写 `std::cout` → 除非有命名冲突，否则不额外加 `std::`
- 使用 `endl` 会强制刷新输出流 → OJ 输出统一用 `'\n'`
- `struct student`、`struct window` 这类类型名小写 → C++ 结构体和 C typedef 类型统一用 `PascalCase`
- 手写输出分隔符时容易写反 `first` 逻辑，导致前导空格或漏空格 → 统一使用本规范的输出模式
- C 字符串代码中避免 `strcpy` 这类无边界拷贝 → 即使当前长度可证明安全，也优先写成带容量约束的形式
- `#include <bits/stdc++.h>` 后不要再额外包含 `<numeric>` 等标准头
- 常量命名不要混用 `kMaxNum` 和 `MAX_N`，本仓库统一 `UPPER_SNAKE_CASE`
- 不要为「看起来高级」使用复杂模板、宏元编程或过度抽象，题解应服务于题目本身

## 文件头注释

每题源文件以块注释开头：

```cpp
/* <中文题目标题> for problem <ID> on XDOJ by LyCecilion - C++ version */
```

C 题写：

```c
/* <中文题目标题> for problem <ID> on XDOJ by LyCecilion - Pure C version */
```

文件头后空一行，再写 `#include`。

## 命名规范

| 对象                        | 风格               | 示例                            |
| --------------------------- | ------------------ | ------------------------------- |
| 变量                        | `snake_case`       | `max_len`, `student_count`      |
| 函数                        | `snake_case`       | `is_leap()`, `normalize_word()` |
| C++ 结构体 / C typedef 类型 | `PascalCase`       | `Student`, `Team`, `WordInfo`   |
| 常量                        | `UPPER_SNAKE_CASE` | `MAX_STUDENTS`, `NAME_LEN`      |
| 枚举值                      | `UPPER_SNAKE_CASE` | `NO_TRANS`, `ONE_TRANS`         |
| 类型别名                    | 短小明确           | `i64`, `u64`                    |

- 不使用拼音缩写、无意义的单字母全局变量。
- 局部循环变量可以使用 `i`、`j`、`k`。
- 题面概念应该直接体现在命名里，例如 `score`、`rank`、`window`、`frequency`。

## 缩进和括号

**4 空格缩进**，不使用 Tab。

**统一 K&R 风格**：左大括号与函数/控制流同行。

```cpp
int main(void) {
    if (n > 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        break;
    }
}
```

单行语句也必须加花括号：

```cpp
if (flag) {
    break;
}
```

不要手工维护另一套排版风格。格式以 `.clang-format` 为准，提交前运行：

```sh
just fmt
```

## main 函数签名

统一写：

```cpp
int main(void)
```

`main` 末尾显式 `return 0;`。输入失败、非法输入或题目未定义的场景时，通常直接 `return 0;`，不要输出调试信息或自造错误文本。

## 头文件

**C++：**

```cpp
#include <bits/stdc++.h>
using namespace std;
```

- 不额外包含其他标准库头。
- 已经 `using namespace std;` 后，普通标准库符号不写 `std::`。
- 如果确实存在命名冲突，可以局部使用 `std::`，但这种情况应该很少见。

**C：** 按需包含标准头。

```c
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

## I/O

**C++：**

优先按题目输入格式选择 I/O 家族，而不是机械地使用 `cin` / `cout`。

- 普通空白分隔输入、字符串和容器读写：使用 `cin` / `cout`。
- 固定格式输入，例如 `yyyy/mm/dd`、`hh:mm:ss`、逗号分隔、带固定符号的记录：可以在 C++ 题解里使用 `scanf` / `printf`，通常更直接。
- 极大输入量且 `cin` 仍不够稳时，也可以使用 `scanf` / `printf`。
- 一道题内原则上只使用一个 I/O 家族。不要混用 `cin` / `cout` 与 `scanf` / `printf`。
- 只有使用 `cin` / `cout` 时，才写下面两行：

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

- 换行用 `'\n'`，禁用 `endl`。
- 需要固定小数位数时使用 `fixed << setprecision(n)`。

如果本题选择 `scanf` / `printf`，不要再写 `ios::sync_with_stdio(false);` 和 `cin.tie(nullptr);`。关闭同步后再混用 C stdio 与 C++ iostream，缓冲行为更难推断，OJ 场景下不值得冒险。

**C：** 使用 `scanf` / `printf` 或 `fgets` / `sscanf`。

- 读字符串必须写宽度，例如 `scanf("%20s", word)`。
- 读整行优先使用 `fgets`，再去掉末尾换行。
- 所有输入函数的返回值都要检查。

## 输出格式

输出是 OJ 最容易隐藏陷阱的地方，必须严格按题面和样例：

- 不输出额外提示、调试文本、末尾说明。
- 字面量照抄题面，特别注意 ASCII / 全角标点，例如 `!` 和 `！` 不是同一个字符。
- 默认允许末尾换行；如果题目要求逐字节比较，则在 `problem.toml` 设置 `compare = "exact"`。
- 输出列表时使用统一分隔符模式，避免前导空格：

```cpp
bool first = true;
for (const auto &x : values) {
    if (!first) {
        cout << ' ';
    }
    first = false;
    cout << x;
}
cout << '\n';
```

## 变量和作用域

- **C++：** 就近声明，循环变量在 `for` 头部声明。
- **C：** 允许 C99/C17 就近声明；同一小块逻辑内保持紧凑即可，不必强行放到函数顶部。
- 状态变量要初始化。优先使用 `{}` 零初始化。
- 能放局部就不放全局；确实需要全局数组时，必须用常量说明容量来源。
- 函数不应该偷偷读写过多全局状态。递归、搜索、DP 可以用全局表，但命名要清楚。

## 常量和边界

**C++：** 编译期常量使用 `constexpr`，放入匿名命名空间。

```cpp
namespace {
constexpr int MAX_N = 1000;
constexpr int NAME_LEN = 20;
} // namespace
```

**C：** 使用 `enum` 块定义整型容量常量。

```c
enum {
    MAX_WORDS = 1000,
    WORD_LEN = 21
};
```

- 数组容量必须包含终止符、换行等额外空间，并在注释中说明，例如 `20 chars + '\0'`。
- 不写魔法数字。如果题面给出范围，抽成常量。
- 循环边界优先写成与容器/数组容量一致的形式，不依赖读者心算。

## 类型选择

- 普通计数、下标和题面小范围整数使用 `int`。
- 乘法、累加、组合数、金额、距离、时间戳等可能溢出的值使用 `long long` 或别名 `i64`。
- `size_t` 只用于字符串长度、容器大小等自然无符号值。需要输出或和 `int` 比较时，显式转换并确认范围。
- C++ 类型转换使用 `static_cast<T>()`，禁止 C 风格 `(T)x`。
- C 允许 C 风格转换，但在比较器、`ctype.h` 调用等位置要写清楚转换意图。

## 容器和数组

- C++ 默认优先使用 `vector`、`array`、`string`，避免裸动态内存。
- 已知固定小容量使用 `array<T, N>`；题面上界较大或由输入决定时使用 `vector<T>`。
- 需要追加元素且已知上界时，先 `reserve()`。
- `vector<bool>` 只在简单布尔位图场景使用；如果需要引用、指针或频繁调试，改用 `vector<char>` / `array<bool, N>`。
- C 题使用定长数组时，所有写入必须受容量约束。
- 禁止 `gets`。避免 `strcpy`、`strcat`、`sprintf`；确需拷贝时优先使用受限长度的写法，并保证手动补 `'\0'`。

## 排序和比较器

- C++ `sort` 比较器返回 `bool`，直接表达严格弱序。

```cpp
sort(stu.begin(), stu.end(), [](const Student &a, const Student &b) {
    if (a.sum != b.sum) {
        return a.sum > b.sum;
    }
    return a.id < b.id;
});
```

- 不要写返回 `-1/0/1` 再包一层 lambda 的 C++ 比较器，除非需要复用给 C 接口。
- C `qsort` 比较器可以返回负数、零、正数，但不要用可能溢出的减法比较，例如 `return a->x - b->x;`。
- 排序规则必须覆盖并列情况。题目保证唯一时，可以用注释说明。

## 浮点和数学函数

- 浮点输出必须按题面设置精度，不依赖默认格式。
- 比较浮点数使用误差，例如 `fabs(a - b) < EPS`，不要直接 `==`。
- `sqrt`、`pow` 等返回浮点。整数题里用它们时，转换前后要考虑舍入误差；必要时用整数校正。
- 不要用 `pow(10, k)` 计算整数 10 的幂，改用循环或整数表。

## 函数拆分

- 一题一个文件，函数数量保持克制。
- 重复逻辑、复杂判断、比较规则、数学公式可以提取成函数。
- 只被当前文件使用的辅助函数写 `static`。
- 函数应该有明确职责，不要把输入、计算、输出都塞进一个大辅助函数。

## Debug 宏

使用模板中提供的 `debug()` 宏（通过 `#ifdef LOCAL` 控制）。提交前确认调试代码已关闭。

- `debug()` 只能输出到 `cerr` / `stderr`。
- 不要把调试输出写到 `cout` / `stdout`。
- 不要提交临时 `freopen`、本地路径或手写输入文件名。

## 注释

- 文件头用 `/* */`。
- 行内用 `//`。
- 业务逻辑用中文，技术细节和常见术语可以用英文。
- 注释解释"为什么"，不要复述"做了什么"。
- 题面有特殊保证、隐藏坑或样例歧义时，用短注释写在关键判断旁边。

## 检查流程

新增或整理一道题后至少运行：

```sh
just fmt <ID>
just test <ID>
just check <ID>
```

如果题目涉及边界、递归、数组或字符串，再补充：

```sh
just memcheck <ID>
just bench <ID>
```

提交前自查：

- 文件头、命名、`main(void)`、K&R 风格是否统一
- 是否有 `endl`、无花括号单行分支、`std::cout` 滥用、无边界字符串拷贝
- 所有数组下标、字符串长度、输入宽度是否受题面上界保护
- 输出字面量、空格、换行、全角/半角标点是否与题面一致
- 样例能过不代表隐藏测试能过；如果有可疑边界，应该手工补一两个本地用例验证
