public class Outer
{
	public static void main(String[] args)
	{
		/** new Outer obj **/
		Outer outer = new Outer();
		/** new Inner obj by Outer obj **/
		Outer.Inner inner = outer.new Inner();		
		inner.print("outer.new");

		/** new Inner obj by Outer Function which returns Inner**/
		inner = outer.getInner();
		inner.print("outer.get");

			
	}
	
	public Inner getInner()
	{
		return new Inner();
	}

	public class Inner
	{
		public void print(String str)
		{
			System.out.println(str);
		}
	}
}
