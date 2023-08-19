public class Enum{
	public enum Season{S,W,R,A}
      public static void main(String[] args){
	
	 for(Season Now:Season.value())
	 {
		 switch(Now)
		 {
			 case 1:
			      System.out.println("Summer");
				break;
		      case 2:
			      System.out.println("Winter");
				break;
			 case 3:
			      System.out.println("Spring");
				break;
                   case 4:
			      System.out.println("Fall");
				break;
		 }
	 }
 }
} 
