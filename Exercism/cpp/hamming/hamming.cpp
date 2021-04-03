#include "hamming.h"
#include "string"
namespace hamming {
	int compute(std::string dna_strand_1, std::string dna_strand_2){
		// float count = dna_strand_1.size()>dna_strand_2.size()?dna_strand_1.size()-dna_strand_2.size():dna_strand_2.size()-dna_strand_1.size();
		// unsigned long len_strand = dna_strand_1.size()>dna_strand_2.size()?dna_strand_2.size():dna_strand_1.size();
		if(dna_strand_1.size()!=dna_strand_2.size()){
			throw std::domain_error("Unequal length dna strands// Hamming difference assumes same length");
		}
		float count = 0;
		for(unsigned long i=0;i<dna_strand_1.size();i++){
			if(dna_strand_1[i]!=dna_strand_2[i]) count++;
		}
		return (int)count;
	}
}  // namespace hamming
