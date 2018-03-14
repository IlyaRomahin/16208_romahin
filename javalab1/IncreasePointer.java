public class IncreasePointer implements Command {
	public IncreasePointer() {}
	@Override
	public void execute(ExecutionContext exc) {
		int ptr = exc.getPtr();
		ptr++;
		exc.setPtr(ptr);
	}
}