# 2.9中的内容均由AI生成，因为AI说其他文件夹中均非纯策略模式，故叫AI写了一个纯策略模式

# 2.9-AI：纯策略模式

本示例演示**纯策略模式**，并与本章其他版本对比。

## 各版本在做什么

| 版本 | 模式定位 | 谁创建具体策略 | 客户端怎么用 |
|------|----------|--------------|--------------|
| 2.3 | 简单工厂为主 | `CashFactory` | 拿到 `CashSuper*`，直接 `AcceptCash` |
| 2.5 | 策略雏形 | 客户端 `new` 后传给 Context | `new CashContext(new CashRebate(...))` |
| 2.6 | 策略 + 简单工厂 | **Context 构造函数里**按 type 创建 | `new CashContext("打八折")` |
| **2.9-AI** | **纯策略** | **客户端创建并注入**，Context 不创建 | `CashContext context(new CashRebate(0.8))` |

## 和 2.6 的核心区别

2.6 的 `CashContext` 内部带有工厂逻辑：

```cpp
// 2.6：Context 既封装算法调用，又负责创建
CashContext(string type)
{
    if (type == "打八折")
        m_pCashSuper = new CashRebate(0.8);
    // ...
}
```

2.9-AI 的 `CashContext` **只做两件事**：持有策略、委托调用（还可运行时替换）：

```cpp
// 2.9-AI：Context 不创建策略
explicit CashContext(CashSuper* pCashSuper);
void SetStrategy(CashSuper* pCashSuper);
double GetResult(double money);
```

创建具体策略的 `switch` / `if-else` 留在客户端（或将来交给独立工厂），**不属于 Context**。

## 纯策略模式的结构

```text
客户端                Context              Strategy
main.cpp    -->    CashContext    -->    CashSuper（接口）
  | 创建并注入              | 委托调用              |
  +-- new CashNormal()                     +-- CashNormal
  +-- new CashRebate()                     +-- CashRebate
  +-- new CashReturn()                     +-- CashReturn
```

要点：

1. **Context 与具体策略解耦**：Context 只依赖 `CashSuper` 接口。
2. **策略由外部注入**：符合“开闭”——换算法不必改 Context。
3. **可运行时切换**：`SetStrategy` 演示同一 Context 更换算法，调用方式不变。

## 和简单工厂的关系（再次对照）

- **简单工厂**：解决「根据条件 **创建** 哪个对象」。
- **策略模式**：解决「把算法封装起来，让使用方 **可替换** 地使用」。
- **2.6**：把工厂塞进 Context，客户端最省事，但 Context 职责变重。
- **2.9-AI**：Context 保持纯净；若以后想减少客户端的 `switch`，应另写工厂，而不是写回 Context。

## 如何运行

在仓库根目录：

```bash
cmake -B build
cmake --build build --target 2_9-AI
./build/2_9-AI
```
