import { Button } from "@/components/Button";
import { Form } from "@/components/Form";
import { Input } from "@/components/Input";
import { LoginLayout } from "@/screens/Login/components/LoginLayout";
import { useState } from "react";

export function ForgotPasswordScreen() {
  const [isButtonDisabled, setIsButtonDisabled] = useState(true);

  return (
    <LoginLayout
      title="vamos criar outra senha"
      subtitle="primeiro confirme seu e-mail"
    >
      <Form onFieldsChange={(values) => setIsButtonDisabled(!values.email)}>
        <Input name="email" type="email" label="e-mail" />
        <Button name="submit" disabled={isButtonDisabled}>
          continuar
        </Button>
      </Form>
    </LoginLayout>
  );
}
