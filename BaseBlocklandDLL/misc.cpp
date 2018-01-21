#include "uv8.h"

using namespace v8;

void uv8_guess_handle(const FunctionCallbackInfo<Value> &args) {
	ThrowError(args.GetIsolate(), "Unfinished");
	return;
}

void uv8_version(const FunctionCallbackInfo<Value> &args) {
	args.GetReturnValue().Set(Integer::New(args.GetIsolate(), uv_version()));
	return;
}

void uv8_version_string(const FunctionCallbackInfo<Value> &args) {
	args.GetReturnValue().Set(String::NewFromUtf8(args.GetIsolate(), uv_version_string()));
	return;
}

void uv8_get_process_title(const FunctionCallbackInfo<Value> &args) {
	char procTitle[1024];
	uv_get_process_title(procTitle, 1024);
	args.GetReturnValue().Set(String::NewFromUtf8(args.GetIsolate(), procTitle));
	return;
}

void uv8_set_process_title(const FunctionCallbackInfo<Value> &args) {
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	if (args.Length() != 1) {
		ThrowError(args.GetIsolate(), "Wrong number of arguments");
		return;
	}
	if (!args[0]->IsString()) {
		ThrowError(args.GetIsolate(), "Wrong type of arguments");
		return;
	}
	uv_set_process_title(ToCString(String::Utf8Value(args[0]->ToString())));
	return;
}

void uv8_resident_set_memory(const FunctionCallbackInfo<Value> &args) {
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	size_t residentsize;
	uv_resident_set_memory(&residentsize);
	args.GetReturnValue().Set(Number::New(args.GetIsolate(), residentsize));
	return;
}

void uv8_uptime(const FunctionCallbackInfo<Value> &args) {
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	double uptime;
	uv_uptime(&uptime);
	args.GetReturnValue().Set(Number::New(args.GetIsolate(), uptime));
	return;
}

void uv8_getrusage(const FunctionCallbackInfo<Value> &args) {
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	uv_rusage_t rusage;
	uv_getrusage(&rusage);
	Handle<Object> ru = Object::New(args.GetIsolate());
	Handle<Object> time1 = Object::New(args.GetIsolate());
	time1->Set(String::NewFromUtf8(args.GetIsolate(), "usec"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_utime.tv_usec));
	time1->Set(String::NewFromUtf8(args.GetIsolate(), "sec"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_utime.tv_sec));
	Handle<Object> time2 = Object::New(args.GetIsolate());
	time2->Set(String::NewFromUtf8(args.GetIsolate(), "usec"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_stime.tv_usec));
	time2->Set(String::NewFromUtf8(args.GetIsolate(), "sec"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_stime.tv_sec));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "utime"), time1);
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "stime"), time2);
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "maxrss"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_maxrss));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "ixrss"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_ixrss));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "idrss"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_idrss));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "isrss"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_isrss));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "minflt"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_minflt));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "majflt"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_majflt));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "nswap"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_nswap));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "inblock"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_inblock));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "oublock"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_oublock));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "msgsnd"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_msgsnd));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "msgrcv"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_msgrcv));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "nsignals"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_nsignals));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "nvcsw"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_nvcsw));
	ru->Set(String::NewFromUtf8(args.GetIsolate(), "nivcsw"), Int32::NewFromUnsigned(args.GetIsolate(), rusage.ru_nivcsw));
	args.GetReturnValue().Set(ru);
	return;
}

void uv8_cpu_info(const FunctionCallbackInfo<Value> &args) {
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	uv_cpu_info_t* cpus;
	int count;
	uv_cpu_info(&cpus, &count);
	Handle<Array> ee = Array::New(args.GetIsolate(), count);
	for (int i = 0; i < count; i++) {
		Handle<Object> acpu = Object::New(args.GetIsolate());
		acpu->Set(String::NewFromUtf8(args.GetIsolate(), "model"), String::NewFromUtf8(args.GetIsolate(), cpus[i].model));
		acpu->Set(String::NewFromUtf8(args.GetIsolate(), "speed"), Int32::New(args.GetIsolate(), cpus[i].speed));
		Handle<Object> times = Object::New(args.GetIsolate());
		times->Set(String::NewFromUtf8(args.GetIsolate(), "user"), Int32::NewFromUnsigned(args.GetIsolate(), cpus[i].cpu_times.user));
		times->Set(String::NewFromUtf8(args.GetIsolate(), "nice"), Int32::NewFromUnsigned(args.GetIsolate(), cpus[i].cpu_times.nice));
		times->Set(String::NewFromUtf8(args.GetIsolate(), "sys"), Int32::NewFromUnsigned(args.GetIsolate(), cpus[i].cpu_times.sys));
		times->Set(String::NewFromUtf8(args.GetIsolate(), "idle"), Int32::NewFromUnsigned(args.GetIsolate(), cpus[i].cpu_times.idle));
		times->Set(String::NewFromUtf8(args.GetIsolate(), "irq"), Int32::NewFromUnsigned(args.GetIsolate(), cpus[i].cpu_times.irq));
		acpu->Set(String::NewFromUtf8(args.GetIsolate(), "times"), times);
		ee->Set(i, acpu);
	}
	uv_free_cpu_info(cpus, count);
	args.GetReturnValue().Set(ee);
	
	return;
}

void uv8_interface_addresses(const FunctionCallbackInfo<Value> &args) {
	uv_interface_address_t* ifaces;
	char addr[INET6_ADDRSTRLEN];
	int count;
	uv_interface_addresses(&ifaces, &count);
	Handle<Array> bleh = Array::New(args.GetIsolate(), count);
	for (int i = 0; i < count; i++) {
		Handle<Object> holder = Object::New(args.GetIsolate());
		holder->Set(String::NewFromUtf8(args.GetIsolate(), "name"), String::NewFromUtf8(args.GetIsolate(), ifaces[i].name));
		holder->Set(String::NewFromUtf8(args.GetIsolate(), "internal"), Boolean::New(args.GetIsolate(), ifaces[i].is_internal));
		const char* protostring;
		if (ifaces[i].address.address4.sin_family == AF_INET)
		{
			protostring = "ipv4";
			uv_ip4_name(&ifaces[i].address.address4, addr, sizeof(addr));
		}
		else if (ifaces[i].address.address6.sin6_family == AF_INET6) {
			protostring = "ipv6";
			uv_ip6_name(&ifaces[i].address.address6, addr, sizeof(addr));
		}
		else {
			protostring = "unknown";
			strncpy(addr, "<uknown addr family>", sizeof(addr));
		}
		holder->Set(String::NewFromUtf8(args.GetIsolate(), "address"), String::NewFromUtf8(args.GetIsolate(), addr));
		holder->Set(String::NewFromUtf8(args.GetIsolate(), "protocol"), String::NewFromUtf8(args.GetIsolate(), protostring));
		bleh->Set(i, holder);
	}
	uv_free_interface_addresses(ifaces, count);
	args.GetReturnValue().Set(bleh);
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	return;
}

void uv8_loadavg(const FunctionCallbackInfo<Value> &args) {
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	double average[3];
	uv_loadavg(average);
	Handle<Array> avg = Array::New(args.GetIsolate(), 3);
	for (int i = 0; i < 3; i++) {
		avg->Set(i, Number::New(args.GetIsolate(), average[i]));
	}
	args.GetReturnValue().Set(avg);
	return;
}

void uv8_exepath(const FunctionCallbackInfo<Value> &args) {
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	size_t sz = _MAX_PATH * 2;
	char path[_MAX_PATH * 2];
	if (uv_exepath(path, &sz) != UV_ENOBUFS)
	{
		args.GetReturnValue().Set(String::NewFromUtf8(args.GetIsolate(), path));
	}
	else {
		args.GetReturnValue().SetEmptyString();
	}
	return;
}

void uv8_cwd(const FunctionCallbackInfo<Value> &args) {
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	size_t sz = _MAX_PATH * 2;
	char path[_MAX_PATH * 2];
	if (uv_cwd(path, &sz) != UV_ENOBUFS) {
		args.GetReturnValue().Set(String::NewFromUtf8(args.GetIsolate(), path));
	}
	else {
		args.GetReturnValue().SetEmptyString();
	}
	return;
}

void uv8_os_homedir(const FunctionCallbackInfo<Value> &args) {
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	size_t sz = _MAX_PATH * 2;
	char path[_MAX_PATH * 2];
	if (uv_os_homedir(path, &sz) != UV_ENOBUFS) {
		args.GetReturnValue().Set(String::NewFromUtf8(args.GetIsolate(), path));
	}
	else {
		args.GetReturnValue().SetEmptyString();
	}
	return;
}

void uv8_chdir(const FunctionCallbackInfo<Value> &args) {
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	if (!args[0]->IsString()) {
		ThrowError(args.GetIsolate(), "Expected string as first argument");
		return;
	}
	args.GetReturnValue().Set(Integer::New(args.GetIsolate(), uv_chdir(ToCString(String::Utf8Value(args[0]->ToString())))));
	return;
}

void uv8_get_total_memory(const FunctionCallbackInfo<Value> &args) {
	args.GetReturnValue().Set(Int32::NewFromUnsigned(args.GetIsolate(), uv_get_total_memory()));
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	return;
}

void uv8_hrtime(const FunctionCallbackInfo<Value> &args) {
	args.GetReturnValue().Set(Int32::NewFromUnsigned(args.GetIsolate(), uv_hrtime()));
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	return;
}

void uv8_update_time(const FunctionCallbackInfo<Value> &args) {
	uv_update_time(uv_default_loop());
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	return;
}

void uv8_now(const FunctionCallbackInfo<Value> &args) {
	uv_update_time(uv_default_loop());
	uint64_t highprec = uv_now(uv_default_loop());
	args.GetReturnValue().Set(Uint32::NewFromUnsigned(args.GetIsolate(), highprec));
	//args.GetIsolate()->ThrowException(String::NewFromUtf8(args.GetIsolate(), "Unfinished"));
	return;
}

Handle<ObjectTemplate> uv8_bind_misc(Isolate* this_) {
	Handle<ObjectTemplate> misc = ObjectTemplate::New(this_);
	misc->Set(this_, "guess_handle", FunctionTemplate::New(this_, uv8_guess_handle));
	misc->Set(this_, "version", FunctionTemplate::New(this_, uv8_version));
	misc->Set(this_, "version_string", FunctionTemplate::New(this_, uv8_version_string));
	misc->Set(this_, "get_process_title", FunctionTemplate::New(this_, uv8_get_process_title));
	misc->Set(this_, "set_process_title", FunctionTemplate::New(this_, uv8_set_process_title));
	misc->Set(this_, "resident_set_memory", FunctionTemplate::New(this_, uv8_resident_set_memory));
	misc->Set(this_, "uptime", FunctionTemplate::New(this_, uv8_uptime));
	misc->Set(this_, "getrusage", FunctionTemplate::New(this_, uv8_getrusage));
	misc->Set(this_, "cpu_info", FunctionTemplate::New(this_, uv8_cpu_info));
	misc->Set(this_, "interface_addresses", FunctionTemplate::New(this_, uv8_interface_addresses));
	misc->Set(this_, "loadavg", FunctionTemplate::New(this_, uv8_loadavg));
	misc->Set(this_, "exepath", FunctionTemplate::New(this_, uv8_exepath));
	misc->Set(this_, "cwd", FunctionTemplate::New(this_, uv8_cwd));
	misc->Set(this_, "os_homedir", FunctionTemplate::New(this_, uv8_os_homedir));
	misc->Set(this_, "get_total_memory", FunctionTemplate::New(this_, uv8_get_total_memory));
	misc->Set(this_, "hrtime", FunctionTemplate::New(this_, uv8_hrtime));
	misc->Set(this_, "update_time", FunctionTemplate::New(this_, uv8_update_time));
	misc->Set(this_, "now", FunctionTemplate::New(this_, uv8_now));
	return misc;
}