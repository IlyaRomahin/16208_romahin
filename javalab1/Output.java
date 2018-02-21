public class Output implements Command {
	public Output() {}
	@Override
	public void execute(ExecutionContext exc) {
		java.lang.System.out.println("Output is executing!1!");
	}
}