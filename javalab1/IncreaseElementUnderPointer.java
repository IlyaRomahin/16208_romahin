public class IncreaseElementUnderPointer implements Command {
	public IncreaseElementUnderPointer() {}
	@Override
	public void execute(ExecutionContext exc) {
		java.lang.System.out.println("IncreaseElementUnderPointer is executing!1!");
		byte value = (byte)exc.getElement(exc.getPtr());
		value++;
		exc.setElement(exc.getPtr(), value);
	}
}