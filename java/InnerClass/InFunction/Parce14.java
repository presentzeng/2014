/** something wrong can't compile **/
public class Parce14
{
	public Destination destination(String s)
	{
		class PDestination implements Destination
		{
			private String label;	
			private PDestination(String whereTo)
			{
				label = whereTo;
			}

			public String readLabel()
			{
				return label;
			}
		}
		return new PDestination(s);
	}

	public static void main(String[] args)
	{
		Parce14 p = new Parce14();
		Destination d = p.destination("test now");
	}
}
