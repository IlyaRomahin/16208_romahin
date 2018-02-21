public interface ExecutionContext {
	public void setElement(byte value, int elementNumber);
	public byte getElement(int elementNumber);
	public void setPtr(int value);
	public int getPtr();
	public void setLoopIndex(int value);
	public int getLoopIndex();
	public void setCommandPtr(int elementNumber);
	public int getCommandPtr();
	public String getCommand(int elementNumber);
}