/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache
{
private:
    int capacity;
    list<int> lru; // 开头插入，末尾删除
    /*
    list使用：
    list<int> l;
    l.push_front(1);//头部插入
    l.push_back(2);//尾部插入
    l.pop_front();//头部删除
    l.pop_back();//尾部删除
    l.front();//返回头部元素
    l.back();//返回尾部元素
    l.begin();//返回头部迭代器
    l.end();//返回尾部迭代器
    l.insert(l.begin(), 3);//在头部插入3
    l.erase(l.begin());//删除头部元素
    l.clear();//清空
    l.size();//大小
    l.empty();//是否为空
    l.sort();//排序
    l.unique();//去重
    l.reverse();//反转
    */
    unordered_map<int, pair<int, list<int>::iterator>> cache; // 方便判断是否存在，以及删除
public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        // 没找到
        if (cache.find(key) == cache.end())
            return -1;
        // 找到了，更新值
        lru.erase(cache[key].second);
        lru.push_front(key);
        cache[key].second = lru.begin();
        return cache[key].first;
    }

    void put(int key, int value)
    {
        // 找到了，更新值
        if (cache.find(key) != cache.end())
        {
            lru.erase(cache[key].second);
            lru.push_front(key);
            cache[key] = {value, lru.begin()};
        }
        else
        {
            // 没找到，先判断是否到了最大值
            if (cache.size() == capacity)
            {
                cache.erase(lru.back());
                lru.pop_back();
            }
            // 没到最大值
            lru.push_front(key);
            cache[key] = {value, lru.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
