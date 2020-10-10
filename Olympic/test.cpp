//#include "ompTest.h"

#include "olympic.h"
#include <gtest/gtest.h>
using namespace std;
#include <list>
#include <iterator>
#include<fstream>

class playerdbtest : public ::testing::Test {

protected:
  void SetUp() 
 {
  
  		std::list<string> res;
     		std::list<string> ::iterator iter;
     		std::string Name;
     		std::string Team; 
     		std::string Sport; 
     		std::string Medal;
    		std::string S, T;
    		fstream fin;
    		int count=1;
    		fin.open("my_data.csv", ios::in);

		while(getline(fin, S))
    		{
    			stringstream X(S);
    			while (getline(X, T,'\n'))
   			 {
   	 			res.push_back(T);
    			 }
   	        }
    		iter=res.begin();
   		 ++iter;
   		 for(;iter!=res.end();++iter)
    		{
    			//std::cout<<*iter<<endl;
    			stringstream ss(*iter); 
    			while (ss.good()) 
    			{ 
        			std::string substr; 
        			getline(ss, substr, ','); 
        			switch(count)
        			{
        				case 1:
        					Name=substr;
        					break;
        				case 2:
        					Team=(substr);
        					break;
					case 3:
        					Sport=(substr);
        					break;
					case 4:
        					Medal=(substr);
        				
c.addResult(Name,Team,Sport,Medal);Name="",Team="",Sport="",Medal="",count=0;
						break;
        			
        			}
        			++count;
        			
    			} 
  		}
    
}
  void TearDown() {}
  Olympic c;
};				


TEST(Olympic,maxCount_GOlD){
Olympic o1;

o1.addResult("Edgar Lindenau Aabye","Finland","Swimming","Gold");


EXPECT_EQ("Egypt", o1.maxGold());

}
/*
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
