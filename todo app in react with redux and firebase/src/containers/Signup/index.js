import { MdOutlineLock } from "react-icons/md";
import { AiOutlineMail, AiOutlineUser } from "react-icons/ai";
import { Logos, TextField, Content, Sidebar, Button } from "../../components";
import "./style.css";
import { useState } from "react";
import {
  db,
  auth,
  set,
  createUserWithEmailAndPassword,
  ref,
} from "../../config";
import { Spinner } from "../../components";
import { useForm } from "react-hook-form";
import { useNavigate } from "react-router-dom";
import AuthLayout from "../../components/Layout/AuthLayout";

export default function Signup() {
  let navigate = useNavigate();
  const [loading, setLoading] = useState(false);
  // const [name, setName] = useState('');
  // const [email, setEmail] = useState('');
  // const [password, setPassword] = useState('');
  const { register, handleSubmit, formState } = useForm();
  const registerUser = async (email, password, name) => {
    setLoading(true);
    await createUserWithEmailAndPassword(auth, email, password)
      .then(async (userCredentials) => {
        let uid = userCredentials.user.uid;
        await set(ref(db, `users/${uid}`), {
          name,
          uid,
        })
          .then(() => navigate(`/login`))
          .catch((err) => console.log(err));
      })
      .catch((err) => {
        console.log("user not authenthicated");
        console.log(err);
      });
    setLoading(false);
  };
  return (
    <AuthLayout
      sideTitle={"Welcome Back!"}
      sideText={
        "To keep connected with us please login with your personal info"
      }
      sideBtnText={"Login"}
      sideBtnURL={"/login"}
      heading={"Create Account"}
      subText={"or use your email for registration"}
    >
      <form
        onSubmit={handleSubmit((data) =>
          registerUser(data.email, data.password, data.name)
        )}
      >
        <div style={{ margin: "10px auto" }}>
          <div className="field">
            <label style={{ paddingBottom: "10px" }}>
              <AiOutlineUser size="24px" color="#adadad" />
            </label>
            <input
              placeholder="Full Name"
              type="text"
              {...register("name", {
                required: {
                  value: true,
                  message: "Name is required",
                },
                minLength: {
                  value: 10,
                  message: "Atleast enter 10 characters",
                },
                maxLength: {
                  value: 30,
                  message: "Max 30 characters are allowed",
                },
                pattern: {
                  value: /[a-zA-Z]+$/,
                  message: "Only alphabets are allowed",
                },
              })}
            />
          </div>
          <div style={{ margin: "auto 2%", color: "red", fontSize: 14 }}>
            {formState.errors.name ? (
              <p>
                <small>{formState.errors.name.message}</small>
              </p>
            ) : (
              ""
            )}
          </div>
        </div>
        <div style={{ margin: "10px auto" }}>
          <div className="field">
            <label style={{ paddingBottom: "10px" }}>
              <AiOutlineMail size="24px" color="#adadad" />
            </label>
            <input
              placeholder="Email Address"
              type="email"
              {...register("email", {
                required: {
                  value: true,
                  message: "Email Address is Required",
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
        <div className="10px auto">
          <div className="field">
            <label style={{ paddingBottom: "10px" }}>
              <MdOutlineLock size="24px" color="#adadad" />
            </label>
            <input
              placeholder="Password"
              type="password"
              {...register("password", {
                required: {
                  value: true,
                  message: "Password is Required",
                },
                minLength: {
                  value: 6,
                  message: "Atleast enter six characters",
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
          <button type="submit" className="btn submit-btn">
            {loading ? <Spinner /> : "Sign Up"}
          </button>
        </div>
      </form>
    </AuthLayout>
  );
}
