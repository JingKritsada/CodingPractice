#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    std::stack<std::vector<std::queue<int>>> temp_stack;

    while (!a.empty())
    {
        auto current_vector = a.top();
        for (auto &q : current_vector)
        {
            std::queue<int> updated_queue;
            while (!q.empty())
            {
                int value = q.front();
                q.pop();
                updated_queue.push((value == from) ? to : value);
            }
            q = std::move(updated_queue);
        }
        temp_stack.push(std::move(current_vector));
        a.pop();
    }

    while (!temp_stack.empty())
    {
        a.push(std::move(temp_stack.top()));
        temp_stack.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    for (auto &e : a)
    {
        auto &pq = e.second.first;
        std::priority_queue<int> updated_pq;

        while (!pq.empty())
        {
            int value = pq.top();
            pq.pop();
            updated_pq.push((value == from) ? to : value);
        }

        pq = std::move(updated_pq);

        if (e.second.second == from)
        {
            e.second.second = to;
        }
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> updated_set;

    for (const auto &e : a)
    {
        std::list<int> updated_list;
        for (const auto &value : e.first)
        {
            updated_list.push_back((value == from) ? to : value);
        }

        std::map<int, std::pair<int, string>> updated_map;
        for (const auto &m : e.second)
        {
            int new_key = (m.first == from) ? to : m.first;
            int new_value = (m.second.first == from) ? to : m.second.first;
            updated_map.emplace(new_key, std::make_pair(new_value, m.second.second));
        }

        updated_set.emplace(std::move(updated_list), std::move(updated_map));
    }

    a = std::move(updated_set);
}

#endif
