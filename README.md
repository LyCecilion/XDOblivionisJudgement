<!--markdownlint-disable MD033 MD036 MD041-->

<div align="center">

![XDOblivionisJudgement banner](./assets/banner.png)

# XDOblivionisJudgement

💻 由 [零音LyCecilion](https://github.com/LyCecilion) 完成的高质量 XDOJ 题解 🔧

[![Typing SVG](https://readme-typing-svg.demolab.com?font=Cascadia+Code&size=15&duration=3000&pause=500&color=2C81F7&center=true&vCenter=true&multiline=true&width=480&height=90&lines=%E6%88%91%E6%83%B3%E8%A6%81+%E4%B9%98%E7%9D%80%E5%BE%AE%E9%A3%8E%E4%B8%80%E8%B5%B7%E5%87%BA%E5%8F%91+%E5%8E%BB%E7%9C%8B%E7%9C%8B%E5%BD%A9%E8%99%B9%E8%89%B2%E7%9A%84%E4%BA%91%E6%9C%B5+%E5%90%AC%E7%BB%86%E9%9B%A8%E8%90%BD%E4%B8%8B;%E7%94%A8%E9%82%A3%E5%8F%8C%E7%BF%85%E8%86%80+%E9%A3%9E%E5%90%91%E4%BD%A0%E7%9A%84%E6%A2%A6+%E4%BA%94%E5%BD%A9%E6%96%91%E6%96%93%E7%9A%84%E5%A6%84%E6%83%B3+%E5%88%B0%E5%A4%84%E6%9C%9B%E4%B8%80%E6%9C%9B+%E8%BF%99%E4%B8%80%E7%A7%92;%E5%A1%AB%E6%BB%A1%E6%97%A0%E8%89%B2%E7%A9%BA%E7%99%BD%E5%BF%83%E6%88%BF+%E6%97%A0%E6%95%B0%E6%9C%80%E9%97%AA%E4%BA%AE%E7%9A%84%E5%9B%9E%E5%BF%86+%E7%9C%9F%E5%88%87%E7%9A%84%E6%84%BF%E6%9C%9B+%E6%89%8B%E5%BF%83%E7%9A%84%E6%B8%A9%E5%BA%A6;%E6%9C%89%E4%BD%A0%E5%9C%A8%E8%BA%AB%E8%BE%B9+%E6%88%91%E8%83%BD%E4%B8%89%E7%99%BE%E5%88%86%E7%A1%AE%E5%AE%9A+%E6%9C%89%E4%B8%80%E4%BA%9B%E8%AE%B0%E5%BF%86+%E6%B0%B8%E8%BF%9C%E4%B8%8D%E4%BC%9A%E8%A2%AB%E5%90%B9%E5%8E%BB)](https://git.io/typing-svg)

</div>

> [!WARNING]
>
> 该项目代码由 LyCecilion 独立或在 AI 辅助下完成。题解仅作为可能的参考方案，而非 XDOJ 的官方标准。强烈建议将题解仅用于思路启发，请勿在未经思考的情况下直接搬运，以免影响学习效果。本项目不对因不当使用代码而产生的后果负责。
>
> 样例通过只表示本地可见输入输出一致，不等于 XDOJ 的隐藏测试一定通过。资源测量同理。

<div align="center">

![GitHub commit activity](https://img.shields.io/github/commit-activity/m/LyCecilion/XDOblivionisJudgement)
![GitHub last commit](https://img.shields.io/github/last-commit/LyCecilion/XDOblivionisJudgement)
![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/LyCecilion/XDOblivionisJudgement/sample-tests.yml?branch=main)
![GitHub Issues](https://img.shields.io/github/issues/LyCecilion/XDOblivionisJudgement)
![GitHub Pull Requests](https://img.shields.io/github/issues-pr/LyCecilion/XDOblivionisJudgement)
![GitHub License](https://img.shields.io/github/license/LyCecilion/XDOblivionisJudgement)
![GitHub Repo stars](https://img.shields.io/github/stars/LyCecilion/XDOblivionisJudgement)

</div>

## 📖 简介

零音将自己在 XDOJ 上完成题目的题解开源在该 Repo，主要是留作自己做题的记录，同时也供其他同学参考。零音尽可能将代码完成得足够规范、完善、简介、优雅和 robust，并确保每个解答均通过了 XDOJ 的评测且经过 AI 的审核。

目前该 Repo 共含有 <!--problem-count-->17<!--problem-count--> 道题目的题解。每题一个目录，目录中含有题解源码、题目描述、样例数据和思路记录。

## ✨ 特性

- **完全自动的项目运行：** 零音编写本地 OJ 脚本，同时使用 `just` 进行一站式评测、优化、诊断、测试、样式检查等。
- **极致规范的代码风格：** 零音遵循 [CONVENTIONS.md](./CONVENTIONS.md) 编写所有代码，确保题解具有一致的代码规范。
- **简洁高效的逻辑实现：** 零音尽可能将题目的算法编写得足够简洁高效、逻辑清晰。

## 📚 题目列表

<!--markdownlint-disable-->

<div align="center">

<!--problemlist-begins-->
| ID | 标题 | 题解 | 难度 | 语言 |
|:--:|:---|:---:|:---|:--:|
| [4](problems/4/) | [命令行选项](problems/4/README.md) | [main.cpp](problems/4/main.cpp) | ★★★★☆ | C++ |
| [72](problems/72/) | [寻找最长的行](problems/72/README.md) | [main.cpp](problems/72/main.cpp) | ★★☆☆☆ | C++ |
| [73](problems/73/) | [字符串压缩](problems/73/README.md) | [main.cpp](problems/73/main.cpp) | ★★★☆☆ | C++ |
| [74](problems/74/) | [括号匹配](problems/74/README.md) | [main.cpp](problems/74/main.cpp) | ★★★★☆ | C++ |
| [108](problems/108/) | [拼数字](problems/108/README.md) | [main.cpp](problems/108/main.cpp) | ★★★☆☆ | C++ |
| [134](problems/134/) | [数字分解排序](problems/134/README.md) | [main.cpp](problems/134/main.cpp) | ★★★☆☆ | C++ |
| [173](problems/173/) | [购票系统](problems/173/README.md) | [main.cpp](problems/173/main.cpp) | ★★★★★ | C++ |
| [175](problems/175/) | [-](problems/175/README.md) | [main.cpp](problems/175/main.cpp) | - | C++ |
| [242](problems/242/) | [成绩统计](problems/242/README.md) | [main.cpp](problems/242/main.cpp) | ★☆☆☆☆ | C++ |
| [243](problems/243/) | [考试排名](problems/243/README.md) | [main.cpp](problems/243/main.cpp) | ★☆☆☆☆ | C++ |
| [246](problems/246/) | [单词统计](problems/246/README.md) | [main.c](problems/246/main.c) | ★☆☆☆☆ | C |
| [251](problems/251/) | [年月日统计](problems/251/README.md) | [main.cpp](problems/251/main.cpp) | ★☆☆☆☆ | C++ |
| [465](problems/465/) | [排球比赛](problems/465/README.md) | [main.cpp](problems/465/main.cpp) | ★★★☆☆ | C++ |
| [469](problems/469/) | [输入联想](problems/469/README.md) | [main.c](problems/469/main.c) | ★☆☆☆☆ | C |
| [487](problems/487/) | [分段统计学生成绩](problems/487/README.md) | [main.cpp](problems/487/main.cpp) | ★★☆☆☆ | C++ |
| [493](problems/493/) | [找出总分最高的学生](problems/493/README.md) | [main.cpp](problems/493/main.cpp) | ★★★☆☆ | C++ |
| [560](problems/560/) | [子串定位](problems/560/README.md) | [main.cpp](problems/560/main.cpp) | ★★☆☆☆ | C++ |

<!--problemlist-ends-->

</div>

<!--markdownlint-enable-->
<!--markdownlint-disable MD013 MD033-->

运行 `just sync-list` 可自动重新生成上表。

## 🚀 快速开始

Nix 用户可以直接进入开发环境：

```sh
nix develop
```

非 Nix 用户需要自己安装这些命令：

```txt
bash just gcc g++ clang-format clang-tidy diff find awk timeout /usr/bin/time
```

Linux 下的内存检查还需要 `valgrind`。`bench` 和 `memcheck` 是 Linux-only。

## 📁 项目结构

```txt
oj.defaults.toml          # 全局默认语言、时间限制、内存限制
template.c
template.cpp
tools/oj                  # 实际命令逻辑
justfile                  # 用户入口
problems/<id>/
  problem.toml            # 元数据：语言、时限、内存限制、难度等
  main.c | main.cpp       # 题解源码
  README.md               # 题目描述
  NOTES.md                # 解题思路（可选）
  samples/
    1.in / 1.out
```

## 📋 使用

```sh
just list                 # 列出所有题目
just add 200              # 新建 C++ 题目
just add-c 201            # 新建 C 题目
just build 473            # 编译（默认 debug 模式）
just run 473              # 编译并交互运行
just test 473             # 编译并用样例测试
just check 473            # 编译 + 测试 + 静态分析
just bench 473            # 性能测量（release 模式）
just memcheck 473         # Valgrind 内存检查
just fmt                  # 格式化所有代码
just tidy 473             # clang-tidy 静态分析
just commit 473           # 提交题目（自动检测新增/修改）
just sync-list            # 更新 README 题目列表和计数
just clean                # 清理构建产物
```

构建模式：

- `debug`：默认模式，开启 address, undefined sanitizer 和较强警告，适合样例测试。
- `release`：`-O2`，接近 OJ 提交环境，供运行时间和内存测量使用。
- `memcheck`：带调试信息但不启用 sanitizer，供 Valgrind 使用。

## ⚙️ 配置

`problem.toml` 最小内容如下：

```toml
id = 473
language = "c"
source = "main.c"
title = "示例题目"
difficulty = 3
```

如果题面给了限制，可以在对应题目里覆盖默认值：

```toml
time_limit_ms = 1000
memory_limit_mb = 64
memory_limit_kb = 256   # 小于 1MB 时直接用 KB，比如 256KB
compare = "exact"
```

没有写时使用 `oj.defaults.toml`。当前默认值是 `1000 ms`、`128 MiB`，输出比较模式为 `exact`（逐字节严格比较）。如果题目允许忽略行尾空白差异，把题目的 `compare` 改成 `trim-trailing`。

## 🤝 贡献

如果有更好的写法或者想补充新题目的题解，欢迎发送 Pull Request。

## 📄 许可证

[MIT LICENSE](./LICENSE)

> 顶部 Banner 作品版权归属艺术家 **和武はざの（Hazano Kazutake）**。<br/>
> LyCecilion 仅出于学习与欣赏目的使用，如有侵权，请联系 LyCecilion 删除。
