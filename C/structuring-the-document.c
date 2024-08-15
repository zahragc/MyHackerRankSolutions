/*
https://www.hackerrank.com/challenges/structuring-the-document/problem

Structuring the Document 
Difficulty: Hard
Max Score:  60

This answer score: 60
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

// Start answer
char sudodoc [MAX_CHARACTERS + 1];
struct word         wlist [MAX_CHARACTERS];
struct sentence     slist [MAX_CHARACTERS];
struct paragraph    plist [MAX_PARAGRAPHS];

struct document get_document(char* text) {
    struct document mydoc;
    int wstart = 0;
    int wcounter = 0, scounter = 0, pcounter = 0;
    int first_word_index = 0, first_sentence_index = 0;
    
    strncpy(sudodoc, text, strlen(text) + 1);
    
    for(int i=0; i < strlen(text);) {
        wstart = i;
        
        while (sudodoc[i] != ' ' && sudodoc[i] != '.') {
            i++;
        }
    
        // End of a word 
        if (sudodoc[i] == ' ') { 
            wlist[wcounter++].data = &sudodoc[wstart];
            sudodoc[i] = '\0';
            i++;
        }
         
        // End of a sentence
        else if(sudodoc[i] == '.') {
            // end word
            wlist[wcounter++].data = &sudodoc[wstart];
            sudodoc[i] = '\0';
            i++;
            
            // end sentence
            slist[scounter].data = &wlist[first_word_index];
            slist[scounter].word_count = wcounter - first_word_index;
                            
            // new sentence
            first_word_index = wcounter;
            scounter++;
        }             
            
        // End of a paragraph
        if(sudodoc[i] == '\n') {
            // end paragraph
            plist[pcounter].data = &slist[first_sentence_index];
            plist[pcounter].sentence_count = scounter - first_sentence_index;
            sudodoc[i] = '\0';
        
            // new paragraph
            first_sentence_index = scounter;
            pcounter++;
            i++;      
        }
        // End of the document 
        else if(sudodoc[i] == '\0') {
            // end paragraph
            plist[pcounter].data = &slist[first_sentence_index];
            plist[pcounter].sentence_count = scounter - first_sentence_index;

            pcounter++;
            mydoc.data = &plist[0];
            mydoc.paragraph_count = pcounter;
            break;
        }
    } // end for

    return mydoc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}
// End answer

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);
    
    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}