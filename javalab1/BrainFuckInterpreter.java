import java.io.*;
import java.util.ArrayList;

public class BrainFuckInterpreter {
	public void interprete(String fileName) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(fileName));
			char ch;
			while ((ch = (char)br.read()) != -1) {
				if (ch == '\0' || ch == '\n' || ch == ' ') {
					continue;
				}
				Command cmd = Factory.instance().get(String.valueOf(ch));
				commandVec.add(cmd);
			}
		}
		catch(Exception ex){}
		for (commandPtr = 0; commandPtr < commandVec.size(); ++commandPtr) {
			commandVec.get(commandPtr).execute(executionCo);
		}	
	}
	class ExecutionContextImple implements ExecutionContext {
		public void setElement(byte value, int elementNumber) {
			environment[(elementNumber + memorySize) % memorySize] = value;
		}
		public byte getElement(int elementNumber) {
			return environment[(elementNumber + memorySize) % memorySize];
		}
		public void setPtr(int value) {
			ptr = value % memorySize;
		}
		public int getPtr() {
			return ptr;
		}
		public void setLoopIndex(int value) {
			loopIndex = value;
		}
		public int getLoopIndex() {
			return loopIndex;
		}
		public void setCommandPtr(int elementNumber) {
			commandPtr = (elementNumber + commandVec.size()) % commandVec.size();
		}
		public int getCommandPtr() {
			return commandPtr;
		}
		public String getCommand(int elementNumber) {
			return commandVec.get(elementNumber % commandVec.size()).toString();
		}
	}
	private int memorySize = 30000;
	private int ptr = 0;
	private byte environment[] = new byte[memorySize];
	private int commandPtr = 0;
	private ArrayList<Command> commandVec = new ArrayList<>();
	private int loopIndex = 0;
	private ExecutionContextImple executionCo = new ExecutionContextImple();
}