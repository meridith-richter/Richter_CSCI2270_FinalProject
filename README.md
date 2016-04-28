# Richter_CSCI2270_FinalProject
Data Structures Final Project

      I am working alone on this project. I aim to create a program that will allow me to easily check the quality of the ingredients in various cosmetic products. I would like to be able to copy and paste the list of ingredients directly from a web page into a user input that will be analyzed for any overlap of these elements with common comedogenic products or other additives which could adversely effect your skin. Then, instead of reading through 50,000 comments on Sephora.com to see if any person experienced a breakout because of a certain product, I can more immediately tell for myself whether or not this cosmetic item is more prone to affect my skin negatively. Most of the ingredients lists are separated by commas, so I will parse the list this way and compare the elements to pre-made lists of alphabetically-sorted, known comedogenic products. It would also be a future goal to allow for some customization of skin-type, say you have particularly oily skin and could set up that profile for yourself before analyzing ingredients, thereby further tailoring the results of what could potentially be bad for your skin.
      
      INSTRUCTIONS:
      The following are all files used in this program:
            1)main.cpp = driver program
            2)HashTable.h
            3)HashTable.cpp
            4)LinkedList.h
            5)LinkedList.cpp
            6)listFile.txt = internal list of bad ingrediants
            7)ingList.txt = example user list of ingrediants from a product which you can use for running the program
            
      In making a user list of ingrediants for analysis:
            Copy/paste the ingredient list of the cosmetic product of interest into a text file. Delete the period at the end of the list, and any other additional words/periods which are not ingredients or commas but leave all commas. Save that file in the same folder as this program and remember its name. As a command line argument, enter that name with its .txt extension.
            
      Dependencies: no third-party libraries, everything already included
      System Requirements: use on the vm
      Group Members: Meridith Richter
      Contributors: none so far
      Issues: So I implemented both the ingredients list from the user and the bad ingredients list from within the project into alphabetically sorted hash tables. This means that the hash table for each is of a size 26, and each key corresponds to the indexes of the alphabetic letters. Each ingredient is sorted into the corresponding keyed position that matches with its first letter. I would really like to use this hash table implementation to compare the ingredients of the user's product to the bad ingredients, all with the same key. I am still not sure the best way to do this with the methods I have in place for the hash table setup. Any ideas would be greatly appreciated! I'm continually playing with this. Thank you!
      
      Also, for some reason the cin.ignore() is causing some continuity problems when the menu options are being run... there is a lag where cin is not cleared and the next input gets muddled with the last?


