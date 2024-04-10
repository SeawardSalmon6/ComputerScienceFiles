import { AppHeader } from "../../components/AppHeader";

export function ScreenB() {
  return (
    <AppHeader
      title="Screen B"
      redirectTo={{ path: "screen_a", title: "Screen A" }}
    />
  );
}
