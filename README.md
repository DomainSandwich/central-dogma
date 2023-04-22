# 🧬 The Central Dogma 🧬

This C++ code converts a given DNA string into a corresponding protein sequence, utilizing the standard genetic code. It also includes error checking for the absence of start and stop codons, as well as improper nitrogenous bases in the DNA string.

**Dependencies:**

This code requires the following standard C++ libraries:

      iostream: for input/output operations
      cstdlib: for string/vector implementations
      namespace std: standard syntax namespace

**Usage:**

   1) Provide a valid DNA string as input. The DNA string should only contain the characters 'A', 'C', 'G', and 'T', which represent the four nitrogenous bases: adenine, cytosine, guanine, and thymine, respectively.
  
   2) The code will first check if the provided DNA string contains a valid start codon 'ATG' at the beginning, which signals the beginning of a protein-coding region. If a start codon is not found, an error message will be displayed, and the program will terminate.

   3) The code will then check if the provided DNA string contains a valid stop codon ('TAA', 'TAG', or 'TGA') at the end, which signals the end of a protein-coding region. If a stop codon is not found, an error message will be displayed, and the program will terminate.

   4) The code will also check for any improper nitrogenous bases in the DNA string. If any invalid base is found, an error message will be displayed, and the program will terminate.

   5) If all error checks pass, the code will convert the DNA string into a protein sequence using the standard genetic code, which maps codons to their corresponding amino acids.
  
   6) The resulting protein sequence will be displayed as output.

**Example code:**

      (INPUT) DNA: TACAGCATGCA
      Codon mRNA: AUGUCGUACGU
      Polypeptide: Met Ser Tyr + Extra Nitrogenous Base: GU
