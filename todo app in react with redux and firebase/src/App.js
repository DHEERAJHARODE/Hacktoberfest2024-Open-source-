import { AppRouter } from "./config";
import { Provider } from "react-redux";
import store from "./store";

export default function App() {
  return (
    <Provider store={store}>
      <AppRouter />
    </Provider>
  );
}

