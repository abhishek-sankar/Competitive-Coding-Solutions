#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H
#include <string>
#include <stdexcept>

namespace rna_transcription {
	std::string to_rna(std::string dna_transcription);
	char to_rna(char nucleotide);
}  // namespace rna_transcription

#endif // RNA_TRANSCRIPTION_H