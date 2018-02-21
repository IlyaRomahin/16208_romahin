public class EndLoop implements Command {
	public EndLoop() {}
	@Override
	public void execute(ExecutionContext exc) {
		java.lang.System.out.println("EndLoop is executing!1!");
	}
}