import java.io.*;

public class Factory {
	public static Factory instance() {
		if (f == null) {
			f = new Factory();
		}
		return f;
	}
	@SuppressWarnings({"rawtypes", "unchecked"})
	public Command get(String id) throws Exception {
		Class c = Class.forName(command.getProperty(id));
		Object o = c.getConstructor().newInstance();
		return (Command)o;
	}
	private Factory(){
		InputStream	is = Factory.class.getClassLoader().getResourceAsStream(Config);
		command = new java.util.Properties();
		if (is != null) {
			try {
				command.load(is);
			}
			catch(IOException ioex){}
		}
	}
	private static Factory f = null;
	private String Config = "Config.cfg";
	private java.util.Properties command;
}
