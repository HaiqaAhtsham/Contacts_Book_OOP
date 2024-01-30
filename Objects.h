#pragma once
#include"SearchHistory.h"
class Objects {
	SearchHistory* history_list;
	int history_limit;
	static int history_count;
public:
	Objects();
	SearchHistory* GetSearchHistory();
	void PrintSearchHistory();
	SearchHistory resize_history_list();
};