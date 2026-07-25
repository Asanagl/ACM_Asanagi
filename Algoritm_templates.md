# Algoritm_templates

## STL

### vector

```c++
#include <vector> 			//头文件
vector <type> v (len , val) ; // type 可以是任意数据类型
v.push_back(val) ; 			// 尾插
v.pop_back() ; 				// 尾删
v.size() ; 					// len
v.empty() ; 				// 是否为空
v.front() ;					// 首元素
v.back() ;         			// 尾元素
v.clear() ; 				// 清空元素
v.begin() , v.end()     	// 迭代器
v.find() ;					// 查找,返回迭代器
// find 使用例
auto it = find(v.begin(), v.end(), target);
    // 检查是否找到元素
    if (it != v.end()) {
        cout << "元素 " << target << " 找到在位置: " << distance(v.begin(), it) << endl;
    } else {
       cout << "元素 " << target << " 未找到" << endl;
    }
```

### deque

```c++
#include <deque> 			// 头文件
deque <int> dq ;
dq.push_front (val) ;		// 头插
dq.push_back (val) ;		// 尾插
dq.pop_front() ;			// 头删
dq.pop_back() ;				// 尾删
dq.size()					// len
```

> [!TIP]
>
> **deque** 常用于BFS中，首尾操作均为 O(1) .

### set

```c++
#include <set>				// 头文件
set<type> st ;
s.insert (val) ;			// 插入
s.erase (val) ;				// 删除
s.find(3)					// 查找,如果没找到会返回s.end()
s.size() 					// len
```

> [!TIP]
>
> **set**容器会执行自动排序,并且去重,所有操作均为**O**(nlogn)

### map(<u>红黑树实现</u>)

```c++
#include <map>		 		// 头文件
map <type , type> mp 		// <key , value>
mp[key] = value ;
m.erase("key");         // 删除键为"key"的元素
m.find("key");          // 查找键，返回迭代器
m.count("key");         // 判断键是否存在（0或1）
m.size();               // 键值对个数
```

> [!TIP]
>
> **key**值会自动排序,基于红黑树实现,查找和插入操作为**O**(1) .
>
> (可能会被大常数退化到O(n))

### unordered_set/unordered_map（哈希容器）

```cpp
#include <unordered_set>
#include <unordered_map>
unordered_set<int> us;
us.insert(5);           // 插入
us.count(5);            // 查找（返回0或1）

unordered_map<string, int> um;
um["key"] = 100;        // 插入/修改
```

- **特点**：基于哈希表实现，平均操作复杂度 O(1)，无序，适合对性能要求高的场景。

### stack（栈）

```cpp
#include <stack>
stack<int> st;
st.push(1);             // 入栈
st.pop();               // 出栈（无返回值）
st.top();               // 获取栈顶元素
st.empty();             // 判断是否为空
st.size();              // 栈中元素个数
```

- **特点**：后进先出（LIFO），所有操作 O(1)。

### queue（队列）

```cpp
#include <queue>
queue<int> q;
q.push(1);              // 入队
q.pop();                // 出队（无返回值）
q.front();              // 队首元素
q.back();               // 队尾元素
q.empty();              // 判断空
```

- **特点**：先进先出（FIFO），操作 O(1)。

### priority_queue（优先队列）

```c++
priority_queue<type, container, function> pqe 	// <元素类型，实现容器，排序方式> 默认为降序排列
q.push(val);			// 插入到队尾并排序
q.pop();				// 头删
q.empty() ;				// 检查是否为空
q.emplace() ;			// 构造元素并插入
q.size() 				// len
q.top() ;				// 队首元素
```

> [!CAUTION]
>
> 注意：**priority_queue**取出队首元素是使用**top**，而不是**front**，这点一定要注意！！

## 常用函数

### 排序和（二分）查找

```c++
sort(v.begin(), v.end());                           // 升序排序
sort(v.begin(), v.end(), greater<int>());           // 降序排序
binary_search(v.begin(), v.end(), x);               // 二分查找（需有序）
lower_bound(v.begin(), v.end(), x);                 // 第一个 >=x 的位置
upper_bound(v.begin(), v.end(), x);                 // 第一个 >x 的位置
```

### 元素操作

```cpp
max(a, b);              // 返回较大值
min(a, b);              // 返回较小值
max_element(v.begin(), v.end());    // 返回最大元素迭代器
min_element(v.begin(), v.end());    // 返回最小元素迭代器
accumulate(v.begin() , v.end() , 0LL) ;		//数组求和
```

