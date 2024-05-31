import { mapping, dark } from "@eva-design/eva";
import { ApplicationProvider, IconRegistry } from "@ui-kitten/components";
import { RouterProvider } from "./src/routes/router";
import { EvaIconsPack } from "@ui-kitten/eva-icons";
import myTheme from "./assets/theme.json";

export default function App() {
  return (
    <>
      <IconRegistry icons={EvaIconsPack} />
      <ApplicationProvider
        mapping={mapping}
        theme={myTheme}
        // theme={dark}
      >
        <RouterProvider />
      </ApplicationProvider>
    </>
  );
}
