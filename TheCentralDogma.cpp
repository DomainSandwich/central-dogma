#include <iostream>
#include <cstdlib>
using namespace std;

void DNA_To_Protein()
{

    try
    {
        string DNA;

        cout << "DNA: ";
        cin >> DNA;

        if (cin.fail())
        {
            throw 404;
        }

        string mRNA = "";
        int size;

        size = DNA.length();

        string *nitrogenousArr = new string[size];

        for (int i = 0; i < size; i++)
        {
            nitrogenousArr[i] = DNA.substr(i, 1);
        }

        for (int i = 0; i < size; i++)
        {
            if (nitrogenousArr[i] == "A" || nitrogenousArr[i] == "a")
            {
                nitrogenousArr[i] = "U";
            }
            else if (nitrogenousArr[i] == "T" || nitrogenousArr[i] == "t")
            {
                nitrogenousArr[i] = "A";
            }
            else if (nitrogenousArr[i] == "G" || nitrogenousArr[i] == "g")
            {
                nitrogenousArr[i] = "C";
            }
            else if (nitrogenousArr[i] == "C" || nitrogenousArr[i] == "c")
            {
                nitrogenousArr[i] = "G";
            }
            else
            {
                throw 403;
            }
        }

        for (int i = 0; i < size; i++)
        {
            mRNA.append(nitrogenousArr[i]);
        }

        // Checks if the inputted string has correct nitrogenous bases
        for (int i = 0; i < size; i++)
        {
            if (mRNA.substr(i, 1) == "A" || mRNA.substr(i, 1) == "U" || mRNA.substr(i, 1) == "G" || mRNA.substr(i, 1) == "C")
            {
                continue;
            }
            else
            {
                throw 403;
            }
        }

        string *codonArr = new string[size];

        // Creates an array with each element being a codon
        cout << "Codon mRNA: ";
        for (int i = 0; i < size; i += 3)
        {
            codonArr[i] = mRNA.substr(i, 3);
            cout << codonArr[i];
        }

        cout << endl;

        string codonPossibilities[4][4][4];
        // Adenine = 0, Uracil = 1, Guanine = 2, Cytosine = 3

        // Phenylalanine
        codonPossibilities[1][1][1] = "Phe";
        codonPossibilities[1][1][3] = "Phe";

        // Leucine
        codonPossibilities[1][1][0] = "Leu";
        codonPossibilities[1][1][2] = "Leu";
        codonPossibilities[3][1][1] = "Leu";
        codonPossibilities[3][1][3] = "Leu";
        codonPossibilities[3][1][0] = "Leu";
        codonPossibilities[3][1][2] = "Leu";

        // Isoleucine
        codonPossibilities[0][1][1] = "Ile";
        codonPossibilities[0][1][3] = "Ile";
        codonPossibilities[0][1][0] = "Ile";

        // Methionine/Start
        codonPossibilities[0][1][2] = "Met";

        // Valine
        codonPossibilities[2][1][1] = "Val";
        codonPossibilities[2][1][3] = "Val";
        codonPossibilities[2][1][0] = "Val";
        codonPossibilities[2][1][2] = "Val";

        // Serine
        codonPossibilities[1][3][1] = "Ser";
        codonPossibilities[1][3][3] = "Ser";
        codonPossibilities[1][3][0] = "Ser";
        codonPossibilities[1][3][2] = "Ser";
        codonPossibilities[0][2][1] = "Ser";
        codonPossibilities[0][2][3] = "Ser";

        // Proline
        codonPossibilities[3][3][1] = "Pro";
        codonPossibilities[3][3][3] = "Pro";
        codonPossibilities[3][3][2] = "Pro";
        codonPossibilities[3][3][3] = "Pro";

        // Threonine
        codonPossibilities[0][3][1] = "Thr";
        codonPossibilities[0][3][3] = "Thr";
        codonPossibilities[0][3][2] = "Thr";
        codonPossibilities[0][3][0] = "Thr";

        // Alanine
        codonPossibilities[2][3][0] = "Ala";
        codonPossibilities[2][3][1] = "Ala";
        codonPossibilities[2][3][2] = "Ala";
        codonPossibilities[2][3][3] = "Ala";

        // Tyrosine
        codonPossibilities[1][0][1] = "Tyr";
        codonPossibilities[1][0][3] = "Tyr";

        // Stop
        codonPossibilities[1][0][0] = "Stop";
        codonPossibilities[1][0][2] = "Stop";
        codonPossibilities[1][2][0] = "Stop";

        // Histidine
        codonPossibilities[0][0][1] = "His";
        codonPossibilities[3][0][3] = "His";

        // Glutamine
        codonPossibilities[3][0][0] = "Gln";
        codonPossibilities[3][0][2] = "Gln";

        // Asparagine
        codonPossibilities[0][0][0] = "Asn";
        codonPossibilities[0][0][3] = "Asn";

        // Lysine
        codonPossibilities[0][0][0] = "Lys";
        codonPossibilities[0][0][2] = "Lys";

        // Aspartic Acid
        codonPossibilities[2][0][1] = "Asp";
        codonPossibilities[2][0][3] = "Asp";

        // Glutamic Acid
        codonPossibilities[2][0][2] = "Glu";
        codonPossibilities[2][0][0] = "Glu";

        // Cysteine
        codonPossibilities[1][2][1] = "Cys";
        codonPossibilities[1][2][3] = "Cys";

        // Tryptophan
        codonPossibilities[1][2][2] = "Trp";

        // Arginine
        codonPossibilities[3][2][0] = "Arg";
        codonPossibilities[3][2][1] = "Arg";
        codonPossibilities[3][2][2] = "Arg";
        codonPossibilities[3][2][3] = "Arg";
        codonPossibilities[0][2][0] = "Arg";
        codonPossibilities[0][2][2] = "Arg";

        // Glycine
        codonPossibilities[2][2][0] = "Gly";
        codonPossibilities[2][2][1] = "Gly";
        codonPossibilities[2][2][2] = "Gly";
        codonPossibilities[2][2][3] = "Gly";

        // Initializes base values
        int firstBase = -1;
        int secondBase = -1;
        int thirdBase = -1;

        int startCodon = -1;
        int stopCodon = -1;

        // Checks for start codon
        for (int i = 0; i < size; i++)
        {
            if (codonArr[i] == "AUG")
            {
                startCodon = i;
                break;
            }
        }

        // Checks for stop codon
        for (int i = 0; i < size; i++)
        {
            if (codonArr[i] == "UGA")
            {
                stopCodon = i;
                break;
            }
            else if (codonArr[i] == "UAA")
            {
                stopCodon = i;
                break;
            }
            else if (codonArr[i] == "UAG")
            {
                stopCodon = i;
                break;
            }
        }

        if (startCodon == -1)
        {
            throw 404;
        }

        // Checks where to end mRNA translation
        int endVal;
        int nonCodonLengthPos = -1;

        if (stopCodon == -1)
        {
            endVal = size;
        }
        else
        {
            endVal = stopCodon;
        }

        int counter = 1;

        string protein;

        // Calculates amino acid using nested for-loop
        for (int i = startCodon; i < endVal; i += 3)
        {
            counter = 1;
            if (codonArr[i].length() != 3)
            {
                nonCodonLengthPos = i;
                break;
            }
            for (int j = 0; j < 3; j++)
            {
                if (counter == 1)
                {
                    if (codonArr[i].substr(j, 1) == "A")
                    {
                        firstBase = 0;
                        counter++;
                    }
                    if (codonArr[i].substr(j, 1) == "U")
                    {
                        firstBase = 1;
                        counter++;
                    }
                    if (codonArr[i].substr(j, 1) == "G")
                    {
                        firstBase = 2;
                        counter++;
                    }
                    if (codonArr[i].substr(j, 1) == "C")
                    {
                        firstBase = 3;
                        counter++;
                    }
                }
                else if (counter == 2)
                {
                    if (codonArr[i].substr(j, 1) == "A")
                    {
                        secondBase = 0;
                        counter++;
                    }
                    if (codonArr[i].substr(j, 1) == "U")
                    {
                        secondBase = 1;
                        counter++;
                    }
                    if (codonArr[i].substr(j, 1) == "G")
                    {
                        secondBase = 2;
                        counter++;
                    }
                    if (codonArr[i].substr(j, 1) == "C")
                    {
                        secondBase = 3;
                        counter++;
                    }
                }
                else if (counter == 3)
                {
                    if (codonArr[i].substr(j, 1) == "A")
                    {
                        thirdBase = 0;
                    }
                    if (codonArr[i].substr(j, 1) == "U")
                    {
                        thirdBase = 1;
                    }
                    if (codonArr[i].substr(j, 1) == "G")
                    {
                        thirdBase = 2;
                    }
                    if (codonArr[i].substr(j, 1) == "C")
                    {
                        thirdBase = 3;
                    }
                }
            }
            protein = protein + codonPossibilities[firstBase][secondBase][thirdBase] + " ";
        }

        // Accounts for "stranded" non-codon nitrogenous bases
        if (nonCodonLengthPos == -1)
        {
            cout << "Polypeptide: " << protein << endl;
        }
        else
        {
            cout << "Polypeptide: " << protein << "+ "
                 << "Extra Nitrogenous Base: " << codonArr[nonCodonLengthPos] << endl;
        }
    }

    // Catches possible errors along the execution of the program
    catch (int number)
    {
        if (number == 403)
        {
            cout << "Invalid DNA! Incorrect nitrogenous bases! Try again!" << endl;
        }
        else if (number == 404)
        {
            cout << "Invalid mRNA! No start/stop codon!" << endl;
        }
    }
}

int main()
{
    DNA_To_Protein();
    system("pause>0");
}