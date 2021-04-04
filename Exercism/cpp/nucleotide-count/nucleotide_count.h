#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include "string"
#include "map"
namespace nucleotide_count {
	class counter{
		public:
		std::string sequence;
		std::map<char, int> counts{{'A',0}, {'T',0}, {'G',0}, {'C',0}};
		std::map<char, int>nucleotide_counts() const;
		int count(char base) const;
		void validate_nucleotide(char sequence) const;		
		counter(std::string input_sequence);
	};
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H