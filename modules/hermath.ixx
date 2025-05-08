// There does not seem to be a set place where to put this module; section,  some put it here some put it under the export module
// The key point to understand is this is required in modules that use #include for normal headers.
module;
export module hermath;

export namespace girlmath {
	int y = 300000;
	int girlfriend(int x) {
		return x * y;
	}

}