import java.io.*;

public class Input implements Command {
	public Input() {}
	@Override
	public void execute(ExecutionContext exc) {
		try {
			char ch = (char)System.in.read();
			exc.setElement((byte)ch, exc.getPtr());
		}
		catch(IOException ioe) {}
	}
}