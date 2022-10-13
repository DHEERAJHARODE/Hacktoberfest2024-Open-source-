import java.util.*;
class HashMap1
{
    public static void main()
    {
        HashMap <String, Integer>hm = new HashMap<String, Integer>();
        hm.put("Delhi", 300000);
        hm.put("Mumbai", 500000);
        hm.put("Pune", 400000);
        hm.put("Calcutta", 800000);
        System.out.println(hm);
        for(String i: hm.keySet())
        {
            if(hm.get(i) > 400000)
            {
                System.out.println("Key: " + i + " Value: " + hm.get(i));
            }
        }
        hm.remove("Mumbai");
        System.out.println(hm);
        hm.replace("Delhi", 300000, 900000);  
        System.out.println(hm);
        TreeMap<String, Integer> sorted = new TreeMap<>(hm); 
        // Displaying the TreeMap which is naturally sorted by Key.
        System.out.println("HashMap Sorted by Key: ");
        for (Map.Entry<String, Integer> entry : sorted.entrySet())
        {
            System.out.println("Key = " + entry.getKey() +  ", Value = " + entry.getValue());    
        }
        //Sorting the HashMap according to value by converting it into a Linked List.
        List <Map.Entry<String, Integer>> list = new LinkedList<Map.Entry<String, Integer>>(hm.entrySet());
        //Sorts the Linked List.
        Collections.sort(list, new Comparator<Map.Entry<String, Integer>>()
        {
            public int compare(Map.Entry<String, Integer> v1, Map.Entry<String, Integer> v2)
            {
                return(v1.getValue()).compareTo(v2.getValue());
            }
        });
        //Creating a new HashMap to store keys and values according to sorted values.
        HashMap<String, Integer> temp = new LinkedHashMap<String, Integer>();
        for(Map.Entry<String, Integer> obj : list) 
        { 
            temp.put(obj.getKey(), obj.getValue()); 
        } 
        //Displays HashMap which has been sorted by Value.
        System.out.println("HashMap Sorted by Value: ");
        for(String i: temp.keySet())
        {
              System.out.println("Key: " + i + ", Value: " + hm.get(i));
        }
    }
}