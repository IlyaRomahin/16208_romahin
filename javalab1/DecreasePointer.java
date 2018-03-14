public class DecreasePointer implements Command {
	public DecreasePointer() {}
	@Override
	public void execute(ExecutionContext exc) {
		int ptr = exc.getPtr();
		ptr--;
		exc.setPtr(ptr);
	}
}