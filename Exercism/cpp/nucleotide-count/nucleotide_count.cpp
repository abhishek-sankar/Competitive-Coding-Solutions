#include "nucleotide_count.h"
#include "stdexcept"
using namespace std;
namespace nucleotide_count {

		map<char, int> counter::nucleotide_counts() const{
			return counts;
		}
		void counter::validate_nucleotide(char base) const{
				if(base!='A' && base!='T' && base!= 'G' && base!= 'C'){
					throw invalid_argument("Bases need to be from A/T/G/C.");
				}
		}
		counter::counter(string input_sequence){
			sequence = input_sequence;
			std::string ATGC = "ATGC";
			for(unsigned long i=0;i<sequence.size();i++){
				if(ATGC.find(sequence[i])!=std::string::npos){
					counts[sequence[i]]++;
				}else{
					throw invalid_argument("Invalid sequence.");
				}
			}			
		}
		int counter::count(char base) const{
			validate_nucleotide(base);
			return counts.at(base);
		}
}  // namespace nucleotide_count
