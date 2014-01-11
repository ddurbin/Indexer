Indexer
=======
This program, given a set of files, will index and parse the files and create an inverted index, which maps each term found in the files to the subset of files that contain that term. The indexer will also track the frequency each term occurs in each file.


Design and Functionality:
! The structure we used is a fixed length hash table design. It's fixed array length of 36 so it has a slot for each number 0-9 and letter a-z. The tokens are mapped to the structure based off the first letter of the token. For example, token 007 would be mapped to array[0], token 911 would be mapped to array[9], token apple would be mapped to array[10], and token zebra would be mapped to array[35]. Each position of the hash table array has a linked list coming of off it holding the tokens in alphabetic order. Each node in that linked list has a pointer to a different linked list keeping track of the files and frequencies in those files that the token occurs in.
! We begin by taking the file path from the command line and then we create a struct dirent. From there we determine whether the given path name is a file or directory. If the initial argument is a file it hashes the file, if it's a directory then it recurses into the directory and ignores hidden files and "." and "..". From here is visits each file and directory and either hashes the file or recurses into the sub-directory and hashes all files contained.
Big-O Analysis:
! The major components that effect our running time are:
1) Turning the file into a string:
! Let n be the number of characters in the file. The characters are copied over one at a time, so the running time is O(n).
2) Getting the tokens from the newly made file string:
! Let n be the numbers of characters in the file string. The ! characters are each checked to see if it is a delimiter or not, then added to the token string if need be. The running time of this is O(n).
3) Inserting the tokens into the hash table:
! Let n be the number of tokens that would be inserted into the hash table. The worst possible case for this would be that all of the words in the directory begin with the same letter and are already in alphabetic order. This would cause the new tokens to be inserted all in the same position in the hash table and each node would have to be inserted at the end of the linked list to maintain alphabetic order in the structure. The worst case running time would be O(n^2) overall.
4) Adding or updating the file occurrences of a token:
! Let n be there number of tokens. The worst case would be for the files that a token occurs in, the number of occurrences increases for each file. This would mean the list of files would have to be resort for each new file. And this would be the case for every token in the hash table. The worst case running time would be O(n^2) overall.
￼5) Freeing the memory allocated for the hash table and all its nodes:
! This is done by for each position in the hash table, we free the linked list of token attached to it, and free the linked list of files coming off each token_node. This running time would be O(n^2).
