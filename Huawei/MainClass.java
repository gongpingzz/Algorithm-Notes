import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
 
/**
 * 输入格式：yyyy-MM-dd HH:mm:ss.fff
 * 2019-01-01 08:59:00.123
 * 2019-01-01 08:59:00.123
 * 2018-12-28 10:08:00.999
 *
 * 输出：3
 *
 * 输入格式：yyyy-MM-dd HH:mm:ss.fff
 * 2019-01-01 08:59:00.123
 * 2019-01-01 08:59:00.123
 *
 * 输出：2
 */
public class MainClass {
    private static Integer n = 50000;
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        List<String> topDates = new ArrayList<>();
        int i = 0;
        while (in.hasNextLine()){
            String orderDate = in.nextLine();
            if(validateDate(orderDate)){
                topDates.add(orderDate);
            }
            i++;
            if(i>=n)break;
        }
        Integer topUserNum =  doGetTopUserNum(topDates);
        System.out.println(topUserNum);
        in.close();
    }
 
    public static Integer doGetTopUserNum(List<String> topDates){
        Integer topUser = 0;
        Map<String,String> map = new HashMap<>();
        if(topDates !=null && topDates.size()!=0){
            for (String topDate:
                    topDates) {
                String[] dateAndSec = topDate.split("\\.");
                String pre = dateAndSec[0];
                String suf = dateAndSec[1];
                putMinValueToMap(pre,suf,map);
            }
 
            for (Map.Entry<String,String> entry:
                    map.entrySet()){
                StringBuffer stringBuffer = new StringBuffer();
                stringBuffer.append(entry.getKey()).append(".").append(entry.getValue());
 
                for (int i = 0; i < topDates.size(); i++) {
                    if(stringBuffer.toString().equals(topDates.get(i))){
                        topUser++;
                    }
                }
            }
 
        }
        return topUser;
    }
 
    public static boolean validateDate(String date){
        Boolean validate = true ;
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
        try {
            simpleDateFormat.parse(date);
        } catch (ParseException e) {
            validate = false;
        }
        return validate;
 
    }
 
    /**
     * 用map放取最小数据
     * @param datePreFix
     * @param datesufFix
     * @param map
     */
    public static void putMinValueToMap(String datePreFix,String datesufFix,Map<String,String> map){
        Integer value = map.get(datePreFix)==null?null:Integer.valueOf(map.get(datePreFix));
        if(value==null){
            map.put(datePreFix,datesufFix);
        }else if(value.intValue() > Integer.valueOf(datesufFix).intValue()){
            map.put(datePreFix,datesufFix);
        }
    }
}
 