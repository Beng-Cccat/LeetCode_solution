## vector

### 特点

- 根据需要自动增大和缩小
- 连续存储（访问元素非常快速）**频繁增减元素**
- 可迭代，可以使用循环来访问元素 **高效随机访问**
- 元素类型任意

### 头
#include<vector>

### 创建

1. 创建空的
vector<T> vec;
2. 指定初始大小和初始值
vector<T> vec(num)
vevtor<T> vec(num,data)
vector<T> vec={data1,data2,data3}
3. 二维创建
vector<vector<T>> vec
vector<vector<T>> vec(row, vector<T>(col, data));

4. 拷贝创建
vector<T> vec1(vec2)
vector<T> vec1=vec2
vector<T> vec1(vec2.begin(),vec2.end())
5. 直接返回
return {data1,data2}

### 添加
vector.push_back(data)

### 访问元素
1. 下标操作符 vec[index]
2. at(index)

### 获取元素数量
size()

### 迭代访问
1. 迭代器
for(auto it=vec.begin();it!=vec.end();it++){
    cout<<*it<<"";
}
2. 范围循环
for(int element:vec){
    cout<<element<<"";
}

### 删除元素

vec.erase(index)
vec.pop_back()

### 清空vector
vec.clear()

### 排序函数
1. sort，默认从小至大
sort(vec.begin(),vec.end())
2. 自定义比较函数（自定义什么是小于<
bool compare(const T &a,const T &b){
    return a.score<b.score;
}
sort(vec.begin(),vec.end(),compare);

### 去重函数
1. 利用set特性
    vector<T> vec;
    set<T> s(vec.begin(),vec.end());
    vec.assign(s.begin(),s.end())
2. 结合sort和unique函数:
    unique()函数将相邻且重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器再用erase函数擦除从这个元素到最后元素的所有的元素
    vector<T> vec;
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end()); 

### 找最大最小值及其索引

vector<T> vec;
int maxVal = *max_element(nums.begin(), nums.end());
int minVal = *min_element(nums.begin(), nums.end());
auto maxIt = max_element(nums.begin(), nums.end());
auto minIt = min_element(nums.begin(), nums.end());
int maxIdx = distance(nums.begin(), maxIt);
int minIdx = distance(nums.begin(), minIt);

## ++
前量自增 ++i：变量先加 1，然后参与表达式
后量自增 i++：先用变量当前值参与表达式，然后变量再加 1

## string

1. strcpy(s1,s2)复制字符串s2到s1
2. strcat(s1,s2)连接字符串s2到字符串s1的末尾
3. s3=s1+s2同上
4. strlen(s1)返回字符串s1的长度
5. strcmp(s1,s2)
   - 如果s1和s2是相同的，则返回 0；
   - 如果s1<s2则返回值小于 0；
   - 如果s1>s2则返回值大于 0。
6. strchr(s1,ch)返回一个指针，指向字符串s1中字符ch的第一次出现的位置
7. strstr(s1,s2)返回一个指针，只想字符串s1中字符串s2的第一次出现的位置
8. string str3；
   int len=str3.size();
9. substr(size_t pos,size_t len)
10. 转换为字符串函数 to_string()

## 栈stack

### 特点

1. 后进先出
2. 基于deque/vector实现

### 基本操作

1. 创建：stack<T> s
2. 添加元素：push()
3. 移除栈顶元素：pop()
4. 返回栈顶元素：top()
5. 检查栈是否为空：empty()
6. 返回栈中元素的数量：size() 
7. 清空：s=stack<T>();

### 单调栈

> 本质上是栈，只是保证每次新元素入栈后，栈内的元素都保持有序

用途：下一个更大元素、上一个更小元素

举例：输入一个数组 `nums`，请你返回一个等长的结果数组，结果数组中对应索引存储着下一个更大元素，如果没有更大的元素，就存 -1

思考：把数组的元素想象成并列站立的人，元素大小想象成人的身高，这些人面对你站成一列，此时，某一元素后面可见的第一个人就是该元素的下一个更大元素，因为比该元素身高低的都被该元素挡住了

于是出现了单调栈问题模板（找下一个更大元素）：

```c++
vector<int> calculateGreaterElement(vector<int>& nums) {
    int n = nums.size();
    // 存放答案的数组
    vector<int> res(n);
    stack<int> s; 
    // 倒着往栈里放
    for (int i = n - 1; i >= 0; i--) {
        // 判定个子高矮
        while (!s.empty() && s.top() <= nums[i]) {
            // 矮个起开，反正也被挡着了。。。
            s.pop();
        }
        // nums[i] 身后的更大元素
        res[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }
    return res;
}
```

（找上一个更小元素：）

```c++
vector<int> calculateSmallerElement(vector<int>& nums) {
    int n = nums.size();
    // 存放答案的数组
    vector<int> res(n,-1);
    stack<int> s; 
    // 倒着往栈里放
    for (int i = 0; i < n ; i++) {
        // 判定个子高矮
        while (!s.empty() && s.top() >= nums[i]) {
            // 矮个起开，反正也被挡着了。。。
            s.pop();
        }
        // nums[i] 身后的更大元素
        res[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }
    return res;
}
```

## 匿名函数

```c++
[捕获列表](参数列表) -> 返回类型 {
    函数体
};
```

### 捕获列表

1. [==]以值传递方式捕获所有外部变量（不能影响原始变量）
2. [&]以引用方式捕获所有外部变量（可以改变外部变量的值）
3. [x]以值传递捕获变量x
4. [&x]以引用捕获变量x

### 举例

```c++
function<void(int)> backtrack=[&](int index){
            //终止条件
            if(index==digits.size()){
                result.push_back(path);
                return;
            }

            //穷举每一个可能的字符
            for(char c:phoneMap[digits[index]]){
                path.push_back(c);  //加进去
                backtrack(index+1); //递归下一层
                path.pop_back();    //撤销选择
            }
        };
```

这是一段需要递归调用自己的匿名函数，将一个Lambda表达式复制给一个function类型的变量backtrack
其中，``function<void(int)>``表示一个可调用对象，其返回类型为void，参数为一个int
而``backtrack = [&](int index) { ... };``则是一个Lambda表达式，

提问：为什么这里的``function<void(int)>``不能使用``auto`/
回答：`auto`不是一个可调用对象，无法自我引用

## 哈希表unordered_map

1. 特点：键值对

2. 初始化
   - 默认构造函数
     unordered_map<T1,T1> hmap;
   - unordered_map<T1,T2> hmap{{T1_data1,T2_data1},{T1_data2,T2_data2},{...},{...}};
   - 已知要创建的哈希表的元素个数时，也可以在初始化列表中指定元素个数
     unordered_map<T1,T2> hmap{{T1_data1,T2_data1},{T1_data2,T2_data2},{...},{...},4};
   - 复制构造
     unordered_map<T1,T2> hmap1{{T1_data1,T2_data1},{T1_data2,T2_data2},{...},{...}};
   - unorder_map<T1,T2> hmap2(hmap1);
   
3. 添加元素
   - 下标运算
     unordered_map<T1,T1> hmap;
     hmap[pos]=data;
   - insert()
     unordered_map<T1,T1> hmap;
     hmap.insert({T1_data,T2_data});
   
4. 常用函数
   1. begin()：返回一个指向哈希表开始位置的迭代器
      unordered_map<T1,T1> hmap;
      unordered_map<T1,T1>::iterator iter=hmap.begin();
   
   2. end()：返回一个指向哈希表结尾位置的下一个元素的迭代器
      unordered_map<T1,T1> hmap;
      unordered_map<T1,T1>::iterator iter=hmap.end();
   
   3. 取得迭代器后可以通过first和second取得其键和值
   
   4. empty()：判断是否为空
   
   5. size()：返回哈希表的大小
   
   6. erase()
      unordered_map<T1,T1> hmap;
      unordered_map<T1,T1>::iterator iter_begin=hmap.begin();
      unordered_map<T1,T1>::iterator iter_end=hmap.end();
      1. 删除某个位置的元素
         hmap.erase(iter_begin);
      2. 删除某个范围的元素
         hmap.erase(iter_begin,iter_end);
      3. 删除某个对应键的键值对
         hmap.erase(key);
   
   7. at()：根据key()查找哈希表中的元素
   
   8. find()：根据key()查找哈希表中的元素，与at()不同的是该函数返回的是迭代器
      1. 如果找到了则返回该key值位置上的迭代器
      2. 如果没找到则返回哈希表最后一个元素下一个位置上的迭代器 **常利用这一特性通过``hmap.find(key)!=hmap.end()``判断哈希表中是否有某键**
   
   9. 遍历：通过迭代器遍历
   
      ```c++
      for (auto it = myMap.begin(); it != myMap.end(); ++it) {
              cout << it->first << " => " << it->second << endl;
          }
      ```
   
      for循环
   
      ```c++
      for (const auto& pair : myMap) {
              cout << pair.first << " => " << pair.second << endl;
          }
      ```
      
      ```c++
      for(auto &[key,count]:hmap){
          ...
      }
      ```
      
      

## set

### 特点

1. 存储了一组唯一的元素，并按照一定顺序进行排列
2. 高效的元素查找、插入和删除
3. 基于红黑树实现   **具有对数时间复杂度的查找、插入和删除**
4. 可存储元素类型：
   1. 元素类型可以比较大小
   2. 元素类型可以被复制和赋值

### 头文件

#include<set>

### 常用操作

1. 插入 insert()
2. 删除 erase()
3. 查找 find()
4. 数量 size()
5. 为空 empty()

## 常用函数

### 次方 

pow(a,b)=a^b

### 绝对值函数

1. ### 整型 int abs(int i)

2. 复数 double cabs(struct complex znum)

3. 双精度浮点型 double fabs(double x)

4. 长整型 long labs(long n)

### 根号函数

sqrt()

### 反转函数

reverse(first,last)：用于反转在[first,last)范围内的函数，没有返回值
eg. vector<T> vec;reverse(vec.begin(),vec.end());

### insert()

用法：在指定位置插入元素

1. 插入单个元素

   ```cpp
   vector<int> v = {1, 2, 3};
   v.insert(v.begin(), 0);  // 在开头插入 0 → {0, 1, 2, 3}
   v.insert(v.end(), 4);    // 在末尾插入 4 → {0, 1, 2, 3, 4}
   ```

2. 插入多个相同元素

   ```cpp
   vector<int> v = {1, 2, 3};
   v.insert(v.begin() + 1, 2, 9); // 从位置 1 开始插入两个 9 → {1, 9, 9, 2, 3}
   ```

   - 第一个参数：迭代器位置
   - 第二个参数：插入的个数
   - 第三个参数：插入的值

3. 插入另一个容器的元素

   ```cpp
   vector<int> v1 = {1, 2, 3};
   vector<int> v2 = {7, 8};
   
   v1.insert(v1.begin() + 1, v2.begin(), v2.end()); 
   // 从 v1 的位置 1 开始插入 v2 所有元素
   // 结果：{1, 7, 8, 2, 3}
   ```


### 求和函数

vector<T> vec;
accumulate(vec.begin(),vec.end(),\_val);

## 二分查找

时间复杂度：O(logn)

```c++
int binarySearch(vector<int>& nums, int target) {
    int left = 0; 
    int right = nums.size()- 1; // 注意

    while(left <= right) {//注意
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid; 
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}
```

## 位运算

### 常用位运算技巧

| 操作      | 示例表达式          | 含义/用途                  |
| --------- | ------------------- | -------------------------- |
| x&1       | 判断奇偶            | 奇数最后一位是1            |
| x&(x-1)   | 清除最低位的1       | 如12%11=8                  |
| x&-x      | 提取最低位的1       | 如12&-12=4                 |
| x\|(1<<i) | 将第i位设为1        |                            |
| x&~(1<<i) | 将第i位设为0        |                            |
| x^(1<<i)  | 翻转第i位           |                            |
| x>>i      | 右移i位             | 即x/2^i（正数）            |
| x<<i      | 左移i位             | 即x*2^i                    |
| ~x        | 位取反              | 1变0，0变1                 |
| x^y       | 仅在x和y的位不同为1 | 常用于找不同或者无进位加法 |

### 常见位运算算法题型

1. 找只出现一次的数字（其余数字出现偶数次/三次）

   1. 数组中一个数字出现一次，其余出现两次 —— 用异或
   2. 数组中一个数字出现一次，其余出现三次 —— 用状态机/位计数

2. 判断一个数是否是2的幂次

   ```c++
   bool isPowerOfTwo(int n) {
       return n > 0 && (n & (n - 1)) == 0;
   }
   ```

   - 负数或者0不可能是2的幂次方
   - 2 的幂的二进制形式中，**只有一个位是 1，其余全是 0**，假设 `n` 是一个 2 的幂，n & (n - 1)` 会把唯一的那个 1 清除掉，结果是 `0000

3. 判断一个数是否是4的幂次

   ```c++
   //位运算+模运算
   bool isPowerOfFour(int n) {
       return n > 0 && (n & (n - 1)) == 0 && (n % 3 == 1);
   }
   
   //位运算+位掩码
   bool isPowerOfFour(int n) {
       return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
   }
   ```

   - `0xAAAAAAAA` 是一个 **32 位中所有偶数位为 1** 的掩码（即 `10101010...`）。
   - `4^k` 中的 `1` 必须出现在 **奇数位（从最低位算第 1、3、5...位）**，所以不能和 `0xAAAAAAAA` 有交集

4. 计算一个整数的二进制中1的个数

   ```c++
   int hammingWeight(uint32_t n) {
       int count = 0;
       while(n){
           n &= (n - 1); // 清除最低位的1
           count++;
       }
       return count;
   }
   ```

5. 两个数之间的汉明距离

   ```c++
   int hammingDistance(int x, int y) {
       return __builtin_popcount(x ^ y); // 或自己写上面那个函数
   }
   ```

6. 交换两个数，不用临时变量

   ```c++
   a = a ^ b;
   b = a ^ b;
   a = a ^ b;
   ```

7. 找数组中两个只出现一次的数

   ```c++
   vector<int> singleNumber(vector<int>& nums) {
       int xor_all = 0;
       for (int num : nums) xor_all ^= num;
       int diff_bit = xor_all & -xor_all; // 找最低不同位
       int a = 0, b = 0;
       for (int num : nums) {
           if (num & diff_bit)
               a ^= num;
           else
               b ^= num;
       }
       return {a, b};
   }
   ```

8. 位运算实现加法

   ```c++
   int getSum(int a, int b) {
       while (b != 0) {
           int carry = (a & b) << 1;
           a = a ^ b;
           b = carry;
       }
       return a;
   }
   ```

8. 压缩空间：比如字符编码，如第题中，DNA 的字符集： `'A'`, `'C'`, `'G'`, `'T'` 一共只有 4 个字符。我们可以用 **2 位**来编码每个字符，故一个长度为 10 的 DNA 子串就可以编码成一个 `2 * 10 = 20` 位的整数（也就是一个 32 位 `int` 足够存储），然后我们可以用哈希表记录这些整数的出现次数，避免存储字符串，从而大大节省空间

## BFS广度优先算法

### queue

1. 特点：先进先出，元素只能从队尾添加，从队首移除
2. queue<T> q;
3. empty()：检查队列是否为空
4. front()：返回队首元素的引用
5. size()：返回队列中的元素数量
6. back()：返回队尾元素的引用
7. push()：在队尾添加一个元素
8. pop()：移除队尾元素
9. 常用链表或动态数组实现

### 特点

从一个顶点开始，辐射状地优先遍历其周围较广的区域

### 流程

1. 把根节点放到队列的末尾

2. 每次从队列的头部取出一个元素，查看这个元素所有的下一级元素，把它们放到队列的末尾，并把这个元素记为它下一级元素的前驱 **无权重的最短路径问题，所以在将元素加入队列末尾时不需要进行排序，因为每次默认权重相同**

3. 找到所要找的元素时结束程序

4. 如果遍历整个树还没有找到，结束程序

   **Dijkstra每次遍历的下一个节点带有权重，所以一般用优先队列进行自动排序**

### 应用

1. 层序遍历
2. 最短路径

### 有向无环图问题

1. 用有向图描述依赖关系（做事情的先后顺序）
2. 拓扑排序：把一个有向无环图转成线性的排序
3. 步骤：
   1. 让入度为0的依次入列
   2. 逐个出列，并减少相关入度
   3. 若入度变为0，则入列
   4. 重复
4. 提问：用什么数据结构去存这些数据
   1. 入度数组 **vector<int> indegree**
   2. 邻接表/哈希表（存储每一个课程的后置课程以方便判断是否需要减少该后置课程的入度）**vector<vector<int>> adjList**
5. 应用：先修课程表问题

## DFS深度优先搜索

1. 图结构
2. 树结构
3. 网格问题

### 主要因素

1. 访问相邻节点
   1. 树结构：左右两个子节点
2. 判断base case
   1. 树结构：root==null

### ==网格问题==

网格问题是由m*n个小方格组成的一个网络，每个小方格与其上下左右四个方格被认为是相邻的，要在这样的网格上进行某种搜索

- 相邻节点：上下左右四个节点
- base case
  - 超出网格范围的格子 **先污染后治理**
  - 网格边缘的格子
- 避免重复遍历——格子的值

## 回溯

模板：

1. 终止条件
2. 穷举每一个可能的字符
3. 回溯
4. 还原状态

技巧：

- problem-47中，在枚举的过程中会有相同元素出现，这个改变有可能导致最后得到的枚举结果重复

  - 一种解决方法是照常进行回溯不剪枝，在得到结果后进行去重（转换为set再转换为vector）

  - 另一种通用的解决方法是进行剪枝，这里提供一种思路：

    ```cpp
    // 剪枝：避免同层重复
    	if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
    ```

    即：相同的数必须按照顺序使用，不能跳过前一个去用后一个，可以避免两个相同的数出现在同一层

## 动态规划

> 关键思想：重叠子问题，最优子结构，状态转移方程

### 表现形式

1. 带备忘录（memo）的递归解法，即「自顶向下」
2. dp table的迭代解法，即「自底向上」

### 和回溯的区别

回溯专注于枚举，而动态规划主要是求最优解以及一些重叠子问题

### ==题型  [题目参考](https://leetcode.cn/discuss/post/3581838/fen-xiang-gun-ti-dan-dong-tai-gui-hua-ru-007o/)==

1. 爬楼梯：最小组合问题，这里一定要注意记忆化，避免重复搜索

2. 打家劫舍：如果取某一个元素，则无法同时取左右相邻元素

   1. 若是环形问题（即第一个和最后一个也算相邻），则可以分成两种情况：不取第一个+不取最后一个，然后取两者最值

3. 最大子数组和（53题），有两种做法：

   1. 定义状态 f[i] 表示以 a[i] 结尾的最大子数组和，不和 i 左边拼起来就是 f[i]=a[i]，和 i 左边拼起来就是 f[i]=f[i−1]+a[i]，取最大值就得到了状态转移方程 f[i]=max(f[i−1],0)+a[i]，答案为 max(f)   **Kadane 算法**

   2. **前缀和**的形式，如第121题，可以转化成：求当前天数以前股票最低价

   3. 若是环形问题，即数组可以跨越最后一个元素回到第一个元素，如第918问题，同样可以考虑两种情况：跨越末尾数组+不跨越末尾数组

      1. 不跨越整个数组：最基础的最大子数组和问题

      2. 跨越整个数组：数组和-最小子数组和

         > 解释：跨越末尾的子数组可以分成两段：左边的一段+右边的一段，不考虑开头和末尾的断开的话，就等价于整个数组总和-中间不选的部分（最小的连续子数组）

      3. 通过以上分析可以得知，似乎不跨越末尾数组的和也可以通过*整个数组总和-中间不选的部分*得到，那么为什么不能只考虑这一种情况呢
         A：当所有元素都是负数时，此时最小子数组就是这个数组本身，最后算出来的结果是0，但是题目要求必须得到至少一个元素，所以至少都得单独考虑这一种情况。
         同时，仔细分析可知，为什么不跨越末尾数组的和!=整个数组总和-中间不选的部分，如果该不跨越末尾数组是处在整个数组中间，也就是说此时该数组和=整个数组总和-前后两个子数组和

4. 网格图dp：其实就是二维的dp数组，更新和一维的一致

   1. 逆向dp（如题174）

      > Q1：为什么这里要用逆向dp
      > A：这里我们并不是想最大化路径和，而是要保证「任何时刻血量不能 ≤ 0」。所以我们需要知道 **当前位置至少要有多少血量** 才能撑到终点；如果我们仍然使用正向dp，我们可以知道自己现在的血量是多少，但并不知道未来路径会掉多少血，所以无法确定此刻的最小需求，即**正向dp无法保证未来存活**，所以我们需要用逆向dp，以保证「从这里出发到终点，一定能活下来」

      > Q2：如何推导转移方程
      > A：我们现在已知且确定`dp[i][j]`=从 `(i,j)` 出发到终点需要的最少初始 HP，在某个格子(i,j)，未来需要的hp是`min(dp[i+1][j], dp[i][j+1])`；同时，当前格子`dungeon[i][j]`的值会影响所需hp，所以`need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]`；再考虑到，hp>0，所以需要设置下限1`dp[i][j] = max(1, need)`

5. 背包问题

   1. 注意这里i的范围是0<=i<=N，j的范围是0<=j<=W

   2. 0-1背包：每个物品只能用一次

      1. 二维dp：`dp[i][j]` 表示前 i 个物品、容量 j 的最优值，`dp[i][j]=max(dp[i−1][j],dp[i−1][j−wi]+vi)`

      2. 一维优化：由上述状态转移方程可知，`dp[i][j]`的值只与`dp[i-1][0,...,j-1]`有关，`dp[j]` 表示**背包容量为 j 时的最大价值**（或者是否可达、最小花费等），关键：**从大到小更新**
         ==注意这里倒序第二维的判断条件是j>=w[i]==

         ```cpp
         for (int i = 0; i < n; i++) {
             for (int j = W; j >= w[i]; j--) { // 倒序
                 dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
             }
         }
         ```

      3. 部分题目需要一些思路的转化才能转换成0-1背包问题，详情见problem-494

      4. 关于正序倒序的问题

         > 解释：对于一维问题来说（即代价只有一个的时候），如果我们使用二维数组来进行dp的构造，则遍历顺序是正序，而如果此时的dp数组是一维数组，那么遍历顺序是倒序遍历；但是，当问题变成二维的时候（即代价有两个，详见problem-474）我们此时至少都要使用二维数组，这时遍历顺序是倒序，所以如何判断应该使用正序还是倒序呢？

         A：遍历顺序的本质是`更新时是否会用到已经更新过的状态`。

         - 对于一维约束的0-1背包，如果此时的dp数组是二维数组，则**第一维是物品维度**，所以可以天然避免重复使用，可以进行正序更新
         - 对于一维约束的0-1背包，如果此时的dp数组是一维数组，则此时**没有物品维度**，如果正序更新可能导致物品重复使用，比如，某物品重量为5(w[0]=5)，则
           dp[0]=0，
           dp[5]=max(dp[5],dp[5-5]+v[0])=dp[0]+v[0]
           dp[10]=max(dp[10],dp[10-5]+v[0])=dp[5]+v[0]=dp[0]+v[0]+v[0]
           此时第一个物品被放入两次
           即：
           正序更新时会用到刚更新过的 `dp[j-5]` → 相当于“再拿一次这个物品” → 完全背包效果
           倒序更新时用的还是旧的 `dp[j-5]` → 确保每个物品只用一次 → 01 背包效果
         - 对于二维约束的0-1背包，此时dp数组最少也是两维，**没有物品维度**，所以无法避免重复使用，只能倒序更新（原理如上一条所述）

         **总结：看该dp数组的设置是否包含物品维度，若包含，则可以正序进行，若不包含，则逆序遍历**

   3. 完全背包

      1. 二维dp：`dp[i][j]=max(dp[i−1][j],dp[i][j−wi]+vi)`

      2. 一维优化：关键：正序，因为正序保证 `dp[j - w[i]]` 是当前物品的状态或者之前物品状态，**可以重复选当前物品**

         ```cpp
         for (int i = 0; i < n; i++) {
             for (int j = w[i]; j <= W; j++) { // 正序
                 dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
             }
         }
         ```

6. 经典线性dp

   1. 最长公共子序列（LCS）

      1. 一般定义 `f[i][j]`表示对 (*s*[:*i*],*t*[:*j*]) 的求解结果

      2. 状态转移方程：
         $$
         dp[i][j] =
         \begin{cases} 
         dp[i-1][j-1] + 1 & \text{if } text1[i-1] = text2[j-1] \\[2mm]
         \max(dp[i-1][j], dp[i][j-1]) & \text{otherwise}
         \end{cases}
         $$
         




## 常用技巧

1. 环形数组：取模运算

## 前缀树/单词查找树/字典树

1. 应用场景：统计、保存大量的字符串，经常被搜索引擎系统用于文本词频统计
2. 优点：利用字符串的公共前缀来减少查找时间，最大限度地减少无谓字符串的比较和存储空间
3. 逻辑结构
   1. 路径+节点
   2. 路径：记载字符串中的字符   **经典的前缀树是以路径记录字符的**
   3. 节点：记载经过的字符串以及结尾字符结尾个数（有几个字符串经过该节点(pass)，有几个字符串以该节点结尾(end)）
   4. 根节点表示空字符串

### 实现：建立TrieNode结构节点

```cpp
//只支持小写字母的
class Trie{
    struct TrieNode{
        bool end;
        TrieNode* tns[26];
        TrieNode(){
            end=false;
            for(int i=0;i<26;i++)
                tns[i]=NULL;
        }
    };
    
    TrieNode* root;
    
public:
    Trie(){
        root=new TrieNode();
    }
    
    void insert(const string& s){
        TrieNode* p=root;
        for(char c:s){
            int u=c-'a';
            if(!p->tns[u]){
                p->tns[i]=new TrieNode();
            }
            p=p->tns[u];
        }
        p->end=true;
    }
    
    bool search(const string& s){
        TrieNode* p=root;
        for(char c:s){
            int u=c-'a';
            if(!p->tns[u])
                return false;
            p=p->tns[u];
        }
        return p->end;
    }
    
    bool startWith(const string& s){
        TrieNode* p=root;
        for(char c:s){
            int u=c-'a';
            if(!p->tns[u])
                return false;
        }
        return true;
    }
}
```

补充：

Q：为什么这里的TrieNode用的是struct而不是class
A：class也是可以嵌套class的，但是因为class默认private，如果不额外加public，该内部class以外的其他变量就不能访问该class内成员，使用class的话是**适合那种需要封装的类**；而struct默认public，**适合纯数据结构**，比较简单

Q：`const string& prefix`
A：

1. &表示引用，如果不加的话就是值传递，函数回拷贝一份字符串，对原来的变量没有影响；加上&之后，函数会直接使用原来的字符串，不会产生拷贝，节省了内存和时间
2. const表示这个引用只读，函数内部不能修改这个字符串
3. `const string&`即指向只读字符串的引用，使用这些限制可以避免不小心修改输入参数，同时还能避免拷贝

```cpp
//通用型
class Trie{
    struct TrieNode{
        bool end;	//是否有以该节点结尾的字符串
        unordered_map<char,TrieNode*>next;	//某个字符所对应的后面的前缀树节点
        TrieNode():end(false){}
    };
    
    TrieNode* root;
    
public:
    Trie(){
        root=new TrieNode();
    }
    
    void insert(const string& s){
        TrieNode* p=root;
        for(char c:s){
            //不断循环，直至找到最后一个字符（如果没有该字符则添加节点）
            if(!p->next.count(c)){
                p->next[c]=new TrieNode();
            }
            p=p->next[c];
        }
        //插入一个字符串，此时p指向字符串最后一个字符
        p->end=true;
    }
    
    bool search(const string& s){
        TrieNode* p=root;
        for(char c:s){
            if(!p->next.count(c))
                return false;
            p=p->next[c];
        }
        return p->end;
    }
    
    //找这个前缀，其实就是相当于search，但是不同的是，此时最后返回的不需要是“该节点指向的是否有单词结尾”，而是前面这些前缀如果都有即可
    bool startWith(const string& prefix){
        TrieNode* p=root;
        for(char c:prefix){
            if(!p->next.count(c))
                return false;
            p=p->next[c];
        }
        return true;
    }
}
```

解释：使用unordered_map的内存占用比固定数组大，适合字符集很大或稀疏的情况
