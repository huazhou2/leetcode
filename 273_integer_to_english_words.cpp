class Solution {
public:
    string numberToWords(int num) {
        unordered_map<int,string> map;
        map[0]="Zero";
        map[1]="One";
        map[2]="Two";
        map[3]="Three";
        map[4]="Four";
        map[5]="Five";
        map[6]="Six";
        map[7]="Seven";
        map[8]="Eight";
        map[9]="Nine";
        map[10]="Ten";
        map[11]="Eleven";
        map[12]="Twelve";
        map[13]="Thirteen";
        map[14]="Fourteen";
        map[15]="Fifteen";
        map[16]="Sixteen";
        map[17]="Seventeen";
        map[18]="Eighteen";
        map[19]="Nineteen";
        map[20]="Twenty";
        map[30]="Thirty";
        map[40]="Forty";
        map[50]="Fifty";
        map[60]="Sixty";
        map[70]="Seventy";
        map[80]="Eighty";
        map[90]="Ninety";
        map[101]="Billion";
        map[102]="Million";
        map[103]="Thousand";
        map[104]="";
        string result="";
        if (num==0) return "Zero";
        int count=0;
        for (int i=1000000000;i>=1000;i=i/1000) {
            count++;
            int cur=num/i;
            if (cur) result=result+num2words3(map,cur) + " " + map[100+count]+ " ";
            num=num%i;
        }
        if (num==0) result.erase(result.size()-1);
        result=result+num2words3(map,num);
        return result;
    }
    string num2words3(unordered_map<int,string>& map, int& num) {
        string result("");
        if (num==0) return result;
        if (num/100) {
            result=result+map[num/100] + " Hundred";
            if (num%100) result=result+ " ";}
        num=num%100;
        if (num>=20) {
            result=result+map[num/10*10];
            num=num%10;
            if (num) result=result+" "+ map[num];
        }
        else if (num>=1) result=result+map[num];
        return result;
    }
};
