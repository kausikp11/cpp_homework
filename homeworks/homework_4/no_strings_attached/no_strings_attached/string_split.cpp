#include <string>
#include <vector>

#include <no_strings_attached/string_split.h>

namespace no_strings_attached {
//namespace string_split {
std::vector<std::string> Split(const std::string& str, const std::string& delimiter){
        //std::cout << " Debug : function entry "<<std::endl;

        int next_start = delimiter.size();

        //std::cout << " Debug : next_start =  "<<next_start<<std::endl;

        std::string::size_type n;
        int n_temp = 0;
        std::vector<int> n_vec;

        std::vector<std::string> container;
        
        std::string split_string;
        std::string string_init = str;  

        // To find indexes of all delimiter (METHOD 1)
        while(string_init.find(delimiter) != std::string::npos){
            //std::cout << " Debug : while loop entry "<<std::endl;

            // search from beginning of string
            n = string_init.find(delimiter);
            //std::cout << "Debug : string_init & n : "<<string_init<<"--"<<n<<std::endl;

            n_vec.push_back (n+n_temp); 
            //std::cout << "Debug : n+n_temp : "<<n+n_temp<<'\t';
            n_temp = n + n_temp + next_start;  
                  
            string_init = string_init.substr(n+next_start);

        }

        if (n_vec.empty()){

            container.push_back(str); 
            return container;

        }else {
           
            for(int i=0; i<n_vec.size(); ++i) {
                //std::cout << " Debug : for loop entry "<<std::endl;

                if (n_vec.front() != 0 && i == 0){
                    split_string = str.substr(0,n_vec.at(i)); //returns [pos, pos+count)
                    container.push_back(split_string);
                    //std::cout << " Debug : @start "<<split_string<<std::endl;
                }

                int Nstart = n_vec.at(i);
                             
                if (i != n_vec.size()-1 ){
                    
                    int Nend = n_vec.at(i+1);

                    if (Nstart+next_start > Nend-1){
                        split_string = ""; 

                    }else{
                        split_string = str.substr(Nstart+next_start,Nend-(Nstart+next_start));
                        //std::cout << " Debug : @middle "<<split_string<<std::endl; 
                    }
                    
                }else if (Nstart < str.size()-1){
                    split_string = str.substr(Nstart+next_start,std::string::npos);
                    //std::cout << " Debug : @end "<<split_string<<std::endl;
                }
                    
                container.push_back(split_string);            

            }
            //std::cout << " Debug : for loop end "<<std::endl;
            return container;
            //std::cout << " Debug : line after return "<<std::endl;
        }
    }
    std::vector<std::string> Split(const std::string& str, const std::string& delimiter, int number_of_chunks_to_keep){

        int next_start = delimiter.size();

        //std::cout << " Debug : next_start =  "<<next_start<<std::endl;

        std::string::size_type n;
        int n_temp = 0;
        std::vector<int> n_vec;

        std::vector<std::string> container;
        
        std::string split_string;
        std::string string_init = str;  

        // To find indexes of all delimiter (METHOD 2)
        if (string_init.find(delimiter) != std::string::npos){
            n = 0;
            //std::cout << "Debug: found delimiter"<<std::endl;

            while (n_temp < str.size()-1){
                
                if (string_init.find(delimiter,n_temp) == std::string::npos){
                    //std::cout << " Debug : while loop break "<<std::endl;
                    break;
                }

                n = string_init.find(delimiter,n_temp);
                n_temp = n + 1;
                n_vec.push_back (n);
                //std::cout << "Debug:n:"<<n<<std::endl;
            }
        }

        if (n_vec.empty()){

            container.push_back(str); 
            return container;

        }else {
           
            for(int i=0; i<n_vec.size(); ++i) {
                //std::cout << " Debug : for loop entry "<<std::endl;

                if (n_vec.front() != 0 && i == 0){
                    split_string = str.substr(0,n_vec.at(i)); //returns [pos, pos+count)
                    container.push_back(split_string);
                    //std::cout << " Debug : @start "<<split_string<<std::endl;
                }

                int Nstart = n_vec.at(i);
                             
                if (i != n_vec.size()-1 ){
                    
                    int Nend = n_vec.at(i+1);

                    if (Nstart+next_start > Nend-1){
                        split_string = ""; 

                    }else{
                        split_string = str.substr(Nstart+next_start,Nend-(Nstart+next_start));
                        //std::cout << " Debug : @middle "<<split_string<<std::endl; 
                    }
                    
                }else if (Nstart < str.size()-1){
                    split_string = str.substr(Nstart+next_start,std::string::npos);
                    //std::cout << " Debug : @end "<<split_string<<std::endl;
                }
                    
                container.push_back(split_string);            

            }

            //std::cout << " Debug : for loop end "<<std::endl;
            if (container.size() > number_of_chunks_to_keep){
                container.resize(number_of_chunks_to_keep) ;
            }
            
            return container;
        }
    }
//} // namespace string_split
} // namespace no_strings_attached
