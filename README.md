<!--markdownlint-disable MD033 MD036 MD041-->

<div align="center">

# XDOblivionisJudgement

![XDOblivionisJudgement 头图](./assets/banner.jpg)

**💻 由 [零音LyCecilion](https://github.com/LyCecilion) 完成的高质量 XDOJ 题解 🔧**
<br/>
完全自动的项目运行 · 极致规范的代码风格 · 简洁高效的逻辑实现

</div>

## 简介

这是 零音LyCecilion 在 XDOJ 上的题解，在 GitHub 上开源，主要是留作自己刷题的记录，同时也供其他同学们参考。在该 Repo 中，零音尽可能将代码写得足够规范、完善、简洁、优雅和鲁棒，每个解答均通过了 XDOJ 的在线评测，且经过 AI 的审核，因此多数情况下，零音可确保这里的题解是万无一失的。

题目正在逐步整理上传中，欢迎持续关注。如果有更好的写法或者想补充新题目的题解，欢迎发送 Pull Request。

## 题目列表

<!--markdownlint-disable-->
<!--problemlist-begins-->

<!--problemlist-ends-->
<!--markdownlint-enable-->
<!--markdownlint-disable MD013-->

运行 `just sync-list` 可自动重新生成上表。

## 环境要求

Nix 用户可以直接进入开发环境：

```sh
nix develop
```

非 Nix 用户需要自己安装这些命令：

```txt
bash just gcc g++ clang-format clang-tidy diff find awk timeout /usr/bin/time
```

Linux 下的内存检查还需要 `valgrind`。`bench` 和 `memcheck` 是 Linux-only。

## 项目结构

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
  samples/
    1.in / 1.out
```

## 常用命令

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
just sync-list            # 更新 README 题目列表
just clean                # 清理构建产物
```

构建模式：

- `debug`：默认模式，开启 address,undefined sanitizer 和较强警告，适合样例测试。
- `release`：`-O2`，接近 OJ 提交环境，供运行时间和内存测量使用。
- `memcheck`：带调试信息但不启用 sanitizer，供 Valgrind 使用。

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
compare = "exact"
```

没有写时使用 `oj.defaults.toml`。当前默认值是 `1000 ms`、`128 MiB`，输出比较模式为 `trim-trailing`，即忽略行尾空白和 CRLF。需要逐字节比较时，把题目的 `compare` 改成 `exact`。

## 免责声明

1. **关于视觉：** 顶部 Banner 作品版权归属艺术家 **和武はざの（Hazano Kazutake）**。LyCecilion 仅出于学习与欣赏目的使用，如有侵权，请联系 LyCecilion 删除。
2. **关于代码：** 本项目代码由 LyCecilion 独立或在 AI 辅助下完成。题解仅作为可能的参考方案，而非 XDOJ 的官方标准。强烈建议将题解仅用于思路启发，请勿在未经思考的情况下直接搬运，以免影响学习效果。本项目不对因不当使用代码而产生的后果负责。
3. **关于评测：** 样例通过只表示本地可见输入输出一致，不等于 XDOJ 的隐藏测试一定通过。资源测量同理。
