import java.io.*;
import java.lang.reflect.*;

public class Factory {
	public static Factory instance() {
		if (f == null) {
			f = new Factory();
		}
	
		return f;
	}
	@SuppressWarnings({"rawtypes", "unchecked"})
	public Command get(String id) {
		Class c = null;
		Object o = null;
		try {
			c = Class.forName(command.getProperty(id));
			o = c.getConstructor().newInstance();
		}
		catch (InstantiationException iex) {}
		catch (ClassNotFoundException cnfe) {}
		catch (NoSuchMethodException nsme) {}
		catch (IllegalAccessException iae) {}
		catch (InvocationTargetException ite) {}
		return (Command)o;
	}
	private Factory(){
		try (InputStream is = Factory.class.getClassLoader().getResourceAsStream(Config)) {
			if (is != null) {
				command.load(is);
			}
		} catch(IOException ioex){}
	}
	private static Factory f = null;
	private String Config = "Config.cfg";
	private java.util.Properties command = new java.util.Properties();
}
