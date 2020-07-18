import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.Map;
import java.util.Scanner;

public class most_frequent{
    public static void main(String args[]){
    Scanner scanner = new Scanner(System.in);
    String result = scanner.nextLine();
	//String text  = "Work yOU Like you do not need money YOu love lIke you have never been hurt YOU dance like no one is watching LiKe someone LIKE me but not SOMEONe Like YOu";
	String str[] = result.split(" ");
	List<String> al = new ArrayList<String>();
	al = Arrays.asList(str);
	for(String s: al){
	   System.out.println(s);
	}
    Map<String, Integer> counter = new TreeMap<String, Integer>(String.CASE_INSENSITIVE_ORDER);
    for (String a : al) {
	    if (counter.containsKey(a)) {
		    int oldValue = counter.get(a);
		    counter.put(a, oldValue + 1);
	    } 
        else {
		    counter.put(a, 1);
	    }
    }
    int maxi = -1;
    String maxword = "";
    for (String name: counter.keySet()){
        int value = counter.get(name);      
        if(value > maxi){
            maxi = value;
            maxword = name;
        }
        if(value==maxi){
            if(name.length()>maxword.length())maxword = name;
        }
    }
    System.out.println("\n"+maxword+" "+Integer.toString(maxi));
    } 
}