//
//  Helper.hpp
//  Trabalho IA
//
//  Created by Yan Mendes on 27/04/17.
//  Copyright © 2017 Yan Mendes. All rights reserved.
//

#ifndef Helper_hpp
#define Helper_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <list>
#include <stdlib.h>
#include <cstdlib>
#include <dirent.h>
#include <cwchar>
#include <time.h>
#include <cstring>
#include <sstream>
#include <ctime>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class Helper{
public:
    int getMax(int * A, int n);
    list<string> getFilesInDirectory(string directory);
    vector<string> explode(std::string const & s, char delim);
    string getCurrentTimeStamp();
};

#endif /* Helper_hpp */
