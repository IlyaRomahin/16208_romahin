public class DecreaseElementUnderPointer implements Command {
	public DecreaseElementUnderPointer() {}
	@Override
	public void execute(ExecutionContext exc) {
		byte value = exc.getElement(exc.getPtr());
		value--;
		exc.setElement(value, exc.getPtr());
	}
}