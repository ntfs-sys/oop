export module stop_words;
import std;

export std::unordered_set<std::string> stop_words = {
    "a","an","the",
    "in","on","at","by","for","with","about","against","between","into","through",
    "during","before","after","above","below","to","from","up","down","out","off",
    "over","under",
    "and","or","but","because","as","until","while","of",
    "i","me","my","mine","myself",
    "you","your","yours","yourself","yourselves",
    "he","him","his","himself",
    "she","her","hers","herself",
    "it","its","itself",
    "we","us","our","ours","ourselves",
    "they","them","their","theirs","themselves",
    "who","whom","whose","which","what",
    "this","that","these","those",
    "all","any","both","each","few","more","most","other","some","such",
    "is","am","are","was","were","be","been","being",
    "have","has","had","having",
    "do","does","did","doing",
    "can","could","will","would","shall","should","may","might","must",
    "not","no","nor","so","too","very","just","than","then",
    "there","here","when","where","why","how","if",
	"one","two","three","four","five","six","seven","eight","nine","ten","upon"
};
