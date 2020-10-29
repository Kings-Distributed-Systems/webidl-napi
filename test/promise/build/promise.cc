#include "node_api.h"
#include "webidl-napi.h"
#include "promise-impl.h"

template <>
napi_status
WebIdlNapi::Converter<FulfillsPromise>::ToNative(
    napi_env env,
    napi_value val,
    FulfillsPromise* result);

template <>
napi_status
WebIdlNapi::Converter<FulfillsPromise>::ToJS(
    napi_env env,
    const FulfillsPromise& val,
    napi_value* result);

template <>
napi_status
WebIdlNapi::Converter<ReturnsPromise>::ToNative(
    napi_env env,
    napi_value val,
    ReturnsPromise* result);

template <>
napi_status
WebIdlNapi::Converter<ReturnsPromise>::ToJS(
    napi_env env,
    const ReturnsPromise& val,
    napi_value* result);

template <>
napi_status
WebIdlNapi::Converter<FulfillsPromise>::ToNative(
    napi_env env,
    napi_value val,
    FulfillsPromise* result) {
  napi_status status;
  {
    napi_value js_member;
    status = napi_get_named_property(env,
        val,
        "name",
        &js_member);
    if (status != napi_ok) return status;

    status = WebIdlNapi::Converter<DOMString>::ToNative(
        env,
        js_member,
        &(result->name));
    if (status != napi_ok) return status;
  }
  return napi_ok;
}

template <>
napi_status
WebIdlNapi::Converter<FulfillsPromise>::ToJS(
    napi_env env,
    const FulfillsPromise& val,
    napi_value* result) {
  napi_status status;
  napi_value ret;
  napi_value
    js_prop_0;

  status = WebIdlNapi::Converter<DOMString>::ToJS(
      env,
      val.name,
      &js_prop_0);
  if (status != napi_ok) return status;

  napi_property_descriptor props[] =
  {
    {
      "name",
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      js_prop_0,
      napi_enumerable,
      nullptr
    }
  };

  status = napi_create_object(
      env,
      &ret);
  if (status != napi_ok) return status;

  status = napi_define_properties(
      env,
      ret,
      sizeof(props) / sizeof(*props),
      props);
  if (status != napi_ok) return status;

  *result = ret;
  return napi_ok;
}

////////////////////////////////////////////////////////////////////////////////
// Interface ReturnsPromise
////////////////////////////////////////////////////////////////////////////////

static napi_value
webidl_napi_interface_ReturnsPromise_constructor(
    napi_env env,
    napi_callback_info info) {
  bool is_construct_call;
  NAPI_CALL(env,
      WebIdlNapi::IsConstructCall(
          env,
          info,
          "ReturnsPromise",
          &is_construct_call));
  if (!is_construct_call) return nullptr;

  napi_value js_ret = nullptr;
  napi_value js_rcv;
  NAPI_CALL(
      env,
      napi_get_cb_info(
          env,
          info,
          nullptr,
          nullptr,
          &js_rcv,
          nullptr));

  ReturnsPromise* ret;
  ret = new ReturnsPromise();
  NAPI_CALL(env,
      napi_wrap(
          env,
          js_rcv,
          static_cast<void*>(ret),
          &WebIdlNapi::ObjectWrapDestructor<ReturnsPromise>,
          nullptr,
          nullptr));

  return js_ret;
}

static napi_value
webidl_napi_interface_ReturnsPromise_requestPromise(
    napi_env env,
    napi_callback_info info) {
  napi_value js_ret = nullptr;
  size_t argc = 1;
  napi_value argv[1];
  napi_value js_rcv;
  NAPI_CALL(
      env,
      napi_get_cb_info(
          env,
          info,
          &argc,
          argv,
          &js_rcv,
          nullptr));
  WebIdlNapi::Promise<FulfillsPromise> ret;
  DOMString native_arg_0;
  NAPI_CALL(
      env,
      WebIdlNapi::Converter<DOMString>::ToNative(
          env,
          argv[0],
          &native_arg_0));

  void* cc_rcv_raw;
  ReturnsPromise* cc_rcv;
  NAPI_CALL(
      env,
      napi_unwrap(
          env,
          js_rcv,
          &cc_rcv_raw));
  cc_rcv = static_cast<ReturnsPromise*>(cc_rcv_raw);

  ret = cc_rcv->requestPromise(native_arg_0);
  NAPI_CALL(env, ret.Conclude(env));

  NAPI_CALL(
      env,
      WebIdlNapi::Promise<FulfillsPromise>::ToJS(
          env,
          ret,
          &js_ret));
  return js_ret;
}

static napi_status
webidl_napi_create_interface_ReturnsPromise(
    napi_env env,
    napi_value* result) {
  napi_property_descriptor props[] =
    {
      {
        "requestPromise",
        nullptr,
        webidl_napi_interface_ReturnsPromise_requestPromise,
        nullptr,
        nullptr,
        nullptr,
        static_cast<napi_property_attributes>(napi_enumerable),
        nullptr
      }
    };

  return napi_define_class(
      env,
      "ReturnsPromise",
      NAPI_AUTO_LENGTH,
      webidl_napi_interface_ReturnsPromise_constructor,
      nullptr,
      sizeof(props) / sizeof(*props),
      props,
      result);
}

////////////////////////////////////////////////////////////////////////////////
// Init module `promise`
////////////////////////////////////////////////////////////////////////////////

napi_value
promise_init(
    napi_env env) {
  napi_value
    interface_0;

  NAPI_CALL(
      env,
      webidl_napi_create_interface_ReturnsPromise(
          env,
          &interface_0));

  napi_property_descriptor props[] =
  {
    {
      "ReturnsPromise",
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      interface_0,
      napi_enumerable,
      nullptr
    }
  };
  napi_value exports;

  NAPI_CALL(
      env,
      napi_create_object(
          env,
          &exports));

  NAPI_CALL(
      env,
      napi_define_properties(
          env,
          exports,
          sizeof(props) / sizeof(*props),
          props));
  return exports;
}
