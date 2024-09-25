class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> output(words.size(), 0);
        int count;
        int count2;

        int searcher;
        int max;
        int min;
        
        string prefix;
        string vergleichs_wort;
        int prefix_lenge;
        int vergleichs_wort_lenge;
        int higher = -1;

        for(int i = 0; i < words.size(); i++){
            prefix = words[i];
            prefix_lenge = prefix.length();
            count = 0;

            higher++;
            int ii = higher;

            for(ii; ii < words.size(); ii++){
                count2 = 0;

                vergleichs_wort = words[ii];
                vergleichs_wort_lenge = vergleichs_wort.length();

                min = 0;
                max = prefix_lenge;
                searcher = max/2;


                if(prefix.substr(0, 1) != vergleichs_wort.substr(0, 1)){
                    ;}
                else if(prefix.substr(0, prefix_lenge) == vergleichs_wort.substr(0, prefix_lenge)){
                    count2 = prefix_lenge;}
                else if(prefix.substr(0, vergleichs_wort_lenge) == vergleichs_wort.substr(0, vergleichs_wort_lenge)){
                    count2 = vergleichs_wort_lenge;}
                else{

                    
                    for(int iii = 1; iii <= prefix_lenge+1; iii++){
                            if(prefix.substr(0, searcher) == vergleichs_wort.substr(0, searcher)){
                                count2 = searcher;
                                min = searcher;
                                if(prefix[searcher] != vergleichs_wort[searcher]){
                                    break;
                                }
                                searcher = searcher+(max - min)/2;
                            }else if(prefix.substr(0, searcher) != vergleichs_wort.substr(0, searcher)){
                                max = searcher;
                                searcher = searcher-(max - min)/2;
                                }
                        }
                }
                if(ii!=i){
                    output[ii]+=count2;
                }
                output[i]+=count2;
            }


        }
        return output;
    }
};
