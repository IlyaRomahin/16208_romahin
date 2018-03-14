public class Output implements Command {
	public Output() {}
	@Override
	public void execute(ExecutionContext exc) {
		char ch = (char)exc.getElement(exc.getPtr());
		System.out.print(ch);
	}
}