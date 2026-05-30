# DataStructure
C++版数据结构实现代码
# 🚀 Advanced Data Structures & Algorithms in C++

[![Language](https://img.shields.io/badge/Language-C%2B%2B%2011%2F14%2F17-blue.svg)](https://en.cppreference.com/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

本仓库是我在攻读/学习计算机科学期间，自主实现的核心**数据结构与算法（C++ 实现）**的完整代码库。
所有代码均遵循现代 C++ 规范，经过严格的边界条件测试，注重内存管理与执行效率，旨在打造一个规范、可复用的算法标准库。

---

## 🛠️ 核心技术亮点与工程规范

在编写本仓库的代码时，我严格遵循了以下工业级开发规范：
* **鲁棒性（Robustness）**：针对图论算法（如 Floyd/Dijkstra），完美修复了经典实现中容易出现的**整数加法溢出**、**重边覆盖**以及**断开点/同点特判**等隐患。
* **现代化 C++ 语法**：合理使用 `std::vector` 等容器，避免原生指针导致的内存泄漏。
* **清晰度（Clarity）**：代码关键步骤配有详尽的中文注释，解释状态转移方程及追踪逻辑。

---

## 📂 知识体系与源码导航

本仓库采用多级 README 架构。点击下方的算法名称，可直接跳转至对应的子文件夹，查看**详细的数学公式推导、示例图解以及独立测试用例**。

### 1. 线性结构 (Linear Structures)
* 🔗 [单/双向链表 (Linked List)](./Linear_Structure/LinkedList) - 支持高频操作及边界安全检查
* 📚 [栈与队列 (Stack & Queue)](./Linear_Structure/Stack_Queue) - 基于数组与链表的双重实现

### 2. 树形结构 (Tree Structures)
* 🌳 [二叉搜索树 (BST)](./Tree/BST) / [AVL 树](./Tree/AVL) - 包含自平衡旋转逻辑
* 🪵 [并查集 (Union-Find)](./Tree/UnionFind) - 包含路径压缩与按秩合并优化

### 3. 图论算法 (Graph Algorithms) 🌟
* 🧮 [图的存储结构](./Graph/Storage) - 邻接矩阵与邻接表的通用模板实现
* 📍 [弗洛伊德算法 (Floyd-Warshall)](./Graph/Floyd_Warshall) - 多源最短路径，支持全路径追踪（推荐阅读）
* 🎯 [迪杰斯特拉算法 (Dijkstra)](./Graph/Dijkstra) - 单源最短路径，支持优先队列堆优化

---

## 📊 核心算法复杂度速查表

| 分类 | 算法/数据结构 | 时间复杂度 (平均/最坏) | 空间复杂度 | 核心优化技术 |
| :---: | :--- | :---: | :---: | :---: |
| **图论** | Floyd-Warshall | $\mathcal{O}(N^3)$ | $\mathcal{O}(N^2)$ | 动态规划、后继路径追踪 |
| **图论** | Dijkstra (堆优化) | $\mathcal{O}((V+E)\log V)$ | $\mathcal{O}(V+E)$ | `std::priority_queue` |
| **树形** | AVL Tree | $\mathcal{O}(\log N)$ | $\mathcal{O}(N)$ | LL/RR/LR/RL 平衡旋转 |
| **集合** | Union-Find | $\mathcal{O}(\alpha(N))$ | $\mathcal{O}(N)$ | 路径压缩 (Path Compression) |

---

## 🚀 如何在本地运行测试？

本仓库所有源码均为独立可执行文件，无需复杂的构建环境：

1. 克隆本仓库到本地：
   ```bash
   git clone [https://github.com/你的用户名/你的仓库名.git](https://github.com/你的用户名/你的仓库名.git)
   cd 你的仓库名
