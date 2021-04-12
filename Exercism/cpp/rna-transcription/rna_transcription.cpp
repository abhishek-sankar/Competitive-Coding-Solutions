#include "rna_transcription.h"

namespace rna_transcription {
	std::string to_rna(std::string dna_transcription) {
		for (unsigned long i = 0;i < dna_transcription.size();i++) {
			if (dna_transcription[i] == 'A') {
				dna_transcription[i] = 'U';
			}			
			else if (dna_transcription[i] == 'T') {
				dna_transcription[i] = 'A';
			}			
			else if (dna_transcription[i] == 'G') {
				dna_transcription[i] = 'C';
			}			
			else if (dna_transcription[i] == 'C') {
				dna_transcription[i] = 'G';
			}			
			else {
				std::invalid_argument("DNA consists of ATGC nucleotides, current input has other bases.");
			}
		}
		return dna_transcription;
	}
	char to_rna(char nucleotide) {
			if (nucleotide == 'A') {
				nucleotide = 'U';
			}			
			else if (nucleotide == 'T') {
				nucleotide = 'A';
			}			
			else if (nucleotide == 'G') {
				nucleotide = 'C';
			}			
			else if (nucleotide == 'C') {
				nucleotide = 'G';
			}			
			else {
				std::invalid_argument("DNA consists of ATGC nucleotides, current input has other bases.");
			}
			return nucleotide;
		}
}  // namespace rna_transcription
