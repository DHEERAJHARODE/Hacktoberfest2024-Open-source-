import { useSelector, useDispatch } from "react-redux";
import { MdOutlineLock } from "react-icons/md";
import { AiOutlineMail } from "react-icons/ai";
import { useNavigate } from "react-router-dom";
import { useForm } from "react-hook-form";
import { useState } from "react";

import { Logos, Content, Sidebar, Button, Spinner } from "../../components";
import { db, auth, signInWithEmailAndPassword } from "../../config";
import { authUserToStore } from "../../store/Actions";
import AuthLayout from "../../components/Layout/AuthLayout";
import "./style.css";
import { Alert } from "reactstrap";
export default function Login() {
  const dispatch = useDispatch();
  let navigate = useNavigate();
  const { register, handleSubmit, formState } = useForm();
  const [loading, setLoading] = useState(false);
  const [formFail, setFormFail] = useState(false);
  let user = useSelector((state) => state.user);
  const signIn = async (email, password) => {
    setLoading(true);
    await signInWithEmailAndPassword(auth, email, password)
      .then(async (userCredential) => {
        console.log("form success");
        // console.log(userCredential.user.uid);
        dispatch(authUserToStore(userCredential.user.uid));
        navigate(`/todos/${userCredential.user.uid}`);
        setFormFail(false);
      })
      .catch((err) => {
        setFormFail(true);
      });
    setLoading(false);
  };
  const closeAlert = () => setFormFail(!formFail);
  return (
    <AuthLayout
      sideTitle="Sign up"
      sideText="To connect with us please sign up with your personal info."
      sideBtnText="Sign up"
      sideBtnURL="/"
      heading={"Sign in "}
      subText="Login"
    >
      <form
        onSubmit={handleSubmit((data) => signIn(data.email, data.password))}
      >
        <div>
          <div
            className="field"
            style={{ border: formState.errors.email ? "1px solid red" : "" }}
          >
            <label style={{ paddingBottom: "10px" }}>
              <AiOutlineMail size="24px" color="#adadad" />
            </label>
            <input
              type="email"
              placeholder="Email Address"
              {...register("email", {
                required: {
                  value: true,
                  message: "Email is required",
                },
                pattern: {
                  value: /[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,4}$/,
                  message: "Incorrect format for email address",
                },
              })}
            />
          </div>
          <div style={{ margin: "auto 2%", color: "red", fontSize: 14 }}>
            {formState.errors.email ? (
              <p>
                <small>{formState.errors.email.message}</small>
              </p>
            ) : (
              ""
            )}
          </div>
        </div>
        <div style={{ margin: "10px auto" }}>
          <div
            className="field"
            style={{ border: formState.errors.password ? "1px solid red" : "" }}
          >
            <label style={{ paddingBottom: "10px" }}>
              <MdOutlineLock size="24px" color="#adadad" />
            </label>
            <input
              placeholder="Password"
              type="password"
              {...register("password", {
                required: {
                  value: true,
                  message: "Password is required",
                },
                minLength: {
                  value: 6,
                  message: "Atleast six characters are required",
                },
              })}
            />
          </div>
          <div style={{ margin: "auto 2%", color: "red", fontSize: 14 }}>
            {formState.errors.password ? (
              <p>
                <small>{formState.errors.password.message}</small>
              </p>
            ) : (
              ""
            )}
          </div>
        </div>
        <div className="d-flex">
          <Button
            type="submit"
            style="btn submit-btn"
            text={loading ? <Spinner /> : "Login"}
          />
        </div>
        <Alert
          color="warning"
          toggle={closeAlert}
          isOpen={formFail}
          fade={true}
        >
          Incorrect Email / Password
        </Alert>
      </form>
    </AuthLayout>
  );
}
