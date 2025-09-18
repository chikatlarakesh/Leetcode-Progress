class TaskManager {
public:
    class comparer {
        public:
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if(a.first != b.first) return a.first > b.first;
            else return a.second > b.second;
        }
    };

    unordered_map<int,set<pair<int,int>>> userIDTaskIDPriority;
    unordered_map<int,int> taskIDPriority;
    unordered_map<int,int> taskIDUserID;
    set<pair<int,int>,comparer> priorityTaskID;


    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0;i<n;i++) {
            int userId = tasks[i][0];
            int taskId = tasks[i][1];
            int priority = tasks[i][2];

            add(userId,taskId,priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        userIDTaskIDPriority[userId].insert({taskId,priority});
        taskIDPriority[taskId] = priority;
        taskIDUserID[taskId] = userId;
        priorityTaskID.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = taskIDPriority[taskId];
        taskIDPriority[taskId] = newPriority;

        int userId = taskIDUserID[taskId];
        userIDTaskIDPriority[userId].erase({taskId,oldPriority});
        userIDTaskIDPriority[userId].insert({taskId,newPriority});

        priorityTaskID.erase({oldPriority,taskId});
        priorityTaskID.insert({newPriority,taskId});

        taskIDPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = taskIDPriority[taskId];
        int userId = taskIDUserID[taskId];
        userIDTaskIDPriority[userId].erase({taskId,priority});

        priorityTaskID.erase({priority,taskId});
        taskIDPriority.erase(taskId);
        taskIDUserID.erase(taskId);
    }
    
    int execTop() {
        if(priorityTaskID.empty()) return -1;

        auto it = priorityTaskID.begin();
        int priority = it->first;
        int taskId = it->second;
        int userId = taskIDUserID[taskId];

        priorityTaskID.erase({priority,taskId});
        userIDTaskIDPriority[userId].erase({taskId,priority});
        taskIDPriority.erase(taskId);
        taskIDUserID.erase(taskId);

        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */