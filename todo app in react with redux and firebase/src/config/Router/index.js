import {
  BrowserRouter,
  Routes,
  Route,
  useLocation,
  Navigate,
  useNavigate,
} from "react-router-dom";
import { Login, Signup, ToDos } from "../../containers";
import { useSelector, useDispatch } from "react-redux";
import { auth, onAuthStateChanged } from "../Firebase";
import { useEffect, useMemo, useState } from "react";
import { authUserToStore } from "../../store/Actions";

export default function AppRouter() {
  const dispatch = useDispatch();
  const [user,setUser] = useState('');
  const [logged, setLogged] = useState(false);
  console.log("app router");
  useEffect(() => {
    onAuthStateChanged(auth, (user) => {
      if (user) {
        dispatch(authUserToStore(user.uid));
        setUser(user.uid);
        setLogged(true);
      }
      else{
        setUser('');
        setLogged(false);
      }
    });
  }, []);
  return (
    <BrowserRouter>
      <Routes>
        <Route
          path="/"
          element={
            <RequireAuthPublic logged={logged} user={user}>
              <Signup />
            </RequireAuthPublic>
          }
        />
        <Route
          path="/login"
          element={
            <RequireAuthPublic logged={logged} user={user}>
              <Login />
            </RequireAuthPublic>
          }
        />
        <Route
          path="/todos/:uid"
          element={
            <RequireAuth logged={logged}>
              <ToDos />
            </RequireAuth>
          }
        />
      </Routes>
    </BrowserRouter>
  );
}
function RequireAuth({ children, logged }) {
  const location = useLocation();
  console.log("private Route");
  // const state = useSelector(state=>state);
  if (!logged) {
    return <Navigate to="/login" replace />;
  }
  return children;
}

function RequireAuthPublic({ children, logged, user }) {
  const location = useLocation();
  // let state = useSelector((state) => state);
  if (logged) {
    return (
      <Navigate to={`/todos/${user}`} replace />
    );
  }
  return children;
}
