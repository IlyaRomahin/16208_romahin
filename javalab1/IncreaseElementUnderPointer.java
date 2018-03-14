public class IncreaseElementUnderPointer implements Command {
	public IncreaseElementUnderPointer() {}
	@Override
	public void execute(ExecutionContext exc) {
		byte value = exc.getElement(exc.getPtr());
		value++;
		exc.setElement(value, exc.getPtr());
	}
}