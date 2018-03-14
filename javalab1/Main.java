public class Main {
	@SuppressWarnings("rawtypes")
	public static void main(java.lang.String[] args) {
		try {
			if (args.length == 0) {
				java.lang.System.out.println("Wrong number of arguments!1!");
				return;
			}
			BrainFuckInterpreter bfi = new BrainFuckInterpreter();
			bfi.interprete(args[0]);
		}
		catch(Exception ex){}
	}
}